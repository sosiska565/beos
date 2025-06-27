#include "timer.h"
#include "../drivers/io.h"
#include "../interrupts/idt.h"
#include "../process/task.h"

unsigned int timer_ticks = 0;

static void timer_handler(struct regs *r){
    timer_ticks++;
    switch_task();
}

void init_timer(void){
    register_irq_handler(0, timer_handler);
}