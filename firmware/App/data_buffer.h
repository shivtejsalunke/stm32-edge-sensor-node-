#ifndef DATA_BUFFER_H
#define DATA_BUFFER_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define DATA_BUFFER_CAPACITY 64U

typedef struct {
    uint32_t timestamp_ms;
    float temperature_c;
    float vibration_rms;
    uint32_t sequence;
    uint8_t simulated;
} telemetry_sample_t;

typedef struct {
    telemetry_sample_t entries[DATA_BUFFER_CAPACITY];
    size_t head;
    size_t tail;
    size_t count;
    uint32_t dropped;
} data_buffer_t;

void data_buffer_init(data_buffer_t *buffer);
bool data_buffer_push(data_buffer_t *buffer, const telemetry_sample_t *sample);
bool data_buffer_pop(data_buffer_t *buffer, telemetry_sample_t *sample);
size_t data_buffer_count(const data_buffer_t *buffer);
#endif
