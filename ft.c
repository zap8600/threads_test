#include <stdlib.h>
#include <stdint.h>
#include <furi.h>

#define TAG "FuriThreadsTest"

static int32_t thread_body(void* context) {
    UNUSED(context);
    FURI_LOG_I(TAG, "Thread code!");
    return 0;
}

int32_t ft_app() {
    FuriThread* thread = furi_thread_alloc();
    furi_thread_set_name(thread, "Test");
    furi_thread_set_stack_size(thread, 1024);
    furi_thread_set_context(thread, thread);
    furi_thread_set_callback(thread, thread_body);
    furi_thread_start(thread);
    FURI_LOG_I(TAG, "Main code!");
    furi_thread_join(thread);
    furi_thread_free(thread);
    return 0;
}
