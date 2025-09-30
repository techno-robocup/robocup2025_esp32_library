#include "armio.hpp"

ARMIO::ARMIO(const std::int8_t& arm_pulse, const std::int8_t& arm_feedback,
             const std::int8_t& wire_sig)
    : arm_pulse_pin(arm_pulse)
    , arm_feedback_pin(arm_feedback)
    , wire_sig_pin(wire_sig)
    , prev_msec(micros())
    , servo_interval(20000)
    ,  // 20ms interval for servo PWM
    kp(0.2)
    , ki(0)
    , kd(0)
    , previous_error(0.0)
    , integral(0.0)
    , target_position(2048) {}  // Start at middle position

ARMIO::ARMIO() {}

void ARMIO::init_pwm() {
  pinMode(arm_pulse_pin, OUTPUT);
  pinMode(arm_feedback_pin, INPUT);
  pinMode(wire_sig_pin, OUTPUT);
  digitalWrite(wire_sig_pin, LOW);
}

int ARMIO::positionToPWM(const int& position) {
  // Convert 0-4095 range to 500-2500µs linearly
  // 500µs = 0°, 1500µs = 90°, 2500µs = 180°
  return 1500 + (position * 1000) / 4095;
}

int ARMIO::getCurrentPosition() {
  // Read analog feedback from arm position sensor
  return analogRead(arm_feedback_pin);
}

void ARMIO::arm_set_position(const int& position) {
  // Clamp position to valid range
  int clamped_position = position;
  if (clamped_position < 0) clamped_position = 0;
  if (clamped_position > 4095) clamped_position = 4095;

  target_position = clamped_position;
}

void ARMIO::wire_tension_function(const bool& enable) {
  int target_angle = enable ? 90 : -90;

  int pwm_value;
  if (target_angle >= 0)
    pwm_value = 1450 + (2400 - 1450) * target_angle / 90;
  else
    pwm_value = 1450 + (1450 - 500) * target_angle / -90;
  digitalWrite(arm_pulse_pin, HIGH);
  delayMicroseconds(pwm_value);
  digitalWrite(arm_pulse_pin, LOW);
}

void ARMIO::updatePID() {
  unsigned long current_micros = micros();
  // Handle micros() overflow (wraps around every ~70 minutes)
  unsigned long elapsed = (current_micros >= prev_msec)
                              ? (current_micros - prev_msec)
                              : (0xFFFFFFFF - prev_msec + current_micros + 1);

  if (elapsed < (unsigned long)servo_interval) {
    return;
  }

  int current_position = getCurrentPosition();
  float error = target_position - current_position;

  // Proportional term
  float proportional = kp * error;

  // Integral term
  integral += error;
  float integral_term = ki * integral;

  // Derivative term
  float derivative = error - previous_error;
  float derivative_term = kd * derivative;

  // Calculate PID output
  float pid_output = proportional + integral_term + derivative_term;

  // Apply PID correction to target position
  int corrected_position = target_position + (int)(pid_output / 10.0);  // Scale down PID output

  // Clamp to valid range
  if (corrected_position < 0) corrected_position = 0;
  if (corrected_position > 4095) corrected_position = 4095;

  // Generate servo PWM signal
  int pulse_width = ARMIO::positionToPWM(corrected_position - target_position);

  digitalWrite(arm_pulse_pin, HIGH);
  delayMicroseconds(pulse_width);
  digitalWrite(arm_pulse_pin, LOW);

  // Update for next iteration
  previous_error = error;
  prev_msec = current_micros;
}
