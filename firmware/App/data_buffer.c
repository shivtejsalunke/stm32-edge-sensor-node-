#include "data_buffer.h"

void data_buffer_init(data_buffer_t *buffer) {
    if (buffer == NULL) return;
    buffer->head = 0U;
    buffer->tail = 0U;
    buffer->count = 0U;
    buffer->dropped = 0U;
}

bool data_buffer_push(data_buffer_t *buffer, const telemetry_sample_t *sample) {
    if (buffer == NULL || sample == NULL) return false;
    if (buffer->count >= DATA_BUFFER_CAPACITY) {
        buffer->dropped++;
        return false; /* explicit drop-newest policy */
    }
    buffer->entries[buffer->head] = *sample;
    buffer->head = (buffer->head + 1U) % DATA_BUFFER_CAPACITY;
    buffer->count++;
    return true;
}

bool data_buffer_pop(data_buffer_t *buffer, telemetry_sample_t *sample) {
    if (buffer == NULL || sample == NULL || buffer->count == 0U) return false;
    *sample = buffer->entries[buffer->tail];
    buffer->tail = (buffer->tail + 1U) % DATA_BUFFER_CAPACITY;
    buffer->count--;
    return true;
}

size_t data_buffer_count(const data_buffer_t *buffer) {
    return buffer == NULL ? 0U : buffer->count;
}
