//
// Created by xander on 20-11-24.
//
#include <linux/module.h>
#include <linux/init.h>


#include "data.h"

// Called when the driver file is opened.
static int file_open(struct inode* device_file, struct file* instance){
    printk("Device file opened\n");
    return 0;
}

// Called when the driver file is closed.
static int file_close(struct inode* device_file, struct file* instance){
    printk("Device file closed\n");
    return 0;
}

const static struct file_operations fops = {
        .owner = THIS_MODULE,
        .open = file_open,
        .release = file_close
};

// Called on module load
static int module_load(void) {

    int ret;
    ret = register_chrdev(90, "kmodule", &fops);
    if (ret == 0){
        printk(load_text);
    } else if (ret > 0){
        printk("Number was already registered?\n");
    } else return -1;

    return 0;
}

// Called on module unload
static void module_unload(void){
    unregister_chrdev(90, "kmodule");
    printk("module unloaded.\n");
    return;
}

module_init(module_load);
module_exit(module_unload);


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Test module for playing around");
