//
// Created by xander on 20-11-24.
//
#include <linux/module.h>
#include <linux/init.h>

int module_load(void) {
    printk("Module loaded\n");
    return 0;
}

void module_unload(void){
    printk("module unloaded.\n");
    return;
}

module_init(module_load);
module_exit(module_unload);


MODULE_LICENSE("GPL");
