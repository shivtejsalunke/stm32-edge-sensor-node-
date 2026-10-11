#ifndef TELEMETRY_H
#define TELEMETRY_H
#include "data_buffer.h"
#include <stdbool.h>
#include <stddef.h>

/* Serializes one bounded JSON object. Returns false if invalid or output is too small. */
bool telemetry_serialize_json(const telemetry_sample_t *sample, char *dst, size_t capacity);
#endif
