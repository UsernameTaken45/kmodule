//
// Created by xander on 20-11-24.
//
#include <linux/module.h>
#include <linux/init.h>


#include "data.h"
int module_load(void) {
    printk(load_text);
    return 0;
}

void module_unload(void){
    printk("module unloaded.\n");
    return;
}

module_init(module_load);
module_exit(module_unload);


MODULE_LICENSE("GPL");
