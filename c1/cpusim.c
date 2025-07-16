#include <stdio.h>
#include <stdint.h> // For uint32_t, uint8_t

// 定义 CSR_COUNT，这是一个假设的常量
#ifndef CSR_COUNT
#define CSR_COUNT 4
#endif

// 定义你的 CPUState 结构体
struct CPUState {
    // Processor internal state
    uint32_t regs[32], csrs[CSR_COUNT];

    // Memory state
    uint8_t *mem;
    uint32_t mem_offset, mem_size;
};

int main() {
    // 声明一个 CPUState 变量
    struct CPUState myCPU;

    // 初始化一些成员（示例）
    for (int i = 0; i < 32; i++) {
        myCPU.regs[i] = i;
    }
    for (int i = 0; i < CSR_COUNT; i++) {
        myCPU.csrs[i] = i * 100;
    }
    // 假设 mem 指向一个内存区域
    uint8_t memory_buffer[1024];
    myCPU.mem = memory_buffer;
    myCPU.mem_offset = 0;
    myCPU.mem_size = 1024;

    // 打印一些信息来验证
    printf("CPUState initialized:\n");
    printf("Register 0: %u\n", myCPU.regs[0]);
    printf("Register 1: %u\n", myCPU.regs[1]);
    printf("CSR 0: %u\n", myCPU.csrs[0]);
    printf("Memory size: %u bytes\n", myCPU.mem_size);

    return 0;
}