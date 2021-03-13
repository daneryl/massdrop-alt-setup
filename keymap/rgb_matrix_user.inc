// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(gaming_layer)
RGB_MATRIX_EFFECT(default_layer)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool gaming_layer(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();
    if (i == 0) {
      rgb_matrix_set_color(i, 255, 255, 0);
      continue;
    }
    if (i == 14) {
      rgb_matrix_set_color(i, 255, 0, 0);
      continue;
    }
    if (i == 17 || i == 31 || i == 32 || i == 33) {
      rgb_matrix_set_color(i, 255, 69, 0);
      continue;
    }
    rgb_matrix_set_color(i, 150, 150, 150);
  }
  return led_max < DRIVER_LED_TOTAL;
}

static bool default_layer(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();
    if (i == 0) {
      rgb_matrix_set_color(i, 255, 255, 0);
      continue;
    }
    if (i == 14) {
      rgb_matrix_set_color(i, 255, 0, 0);
      continue;
    }
    rgb_matrix_set_color(i, 255, 255, 255);
  }
  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
