一个实现了RV32I指令集的单级非流水线CPU。
目前仅能保证非特权指令的运行正确性（至少通过了riscv-tests/isa/gen中的所有测试）。
机器模式特权指令虽然有实现但完全不保证正确性。
各方面性能有待测试，估计不高。（要啥自行车？）
