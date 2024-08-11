#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL"); //*
MODULE_AUTHOR("Nitish"); //!
MODULE_DESCRIPTION("My first dynamically loadable kernel module!"); //!

static int first_module_init(void)
{
    printk("Hello, World! This is Nitish!!\n");
    return 0;
}

static void first_module_exit(void)
{
    printk("Ok, Bye! See you later.\n");
}

module_init(first_module_init);
module_exit(first_module_exit);