#include<linux/init.h>
#include<linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL"); //*
MODULE_AUTHOR("Nitish"); //!
MODULE_DESCRIPTION("Creates entry under proc directory!"); //!

//Taken from proc_fs.h header file
struct proc_dir_entry *proc_entry;
struct proc_ops firstmod_proc_ops = {

};

static int first_module_init(void)
{
    printk("first_module_init: entry\n");
    proc_entry = proc_create("firstmod", 0, NULL, &firstmod_proc_ops);
    printk("first_module_init: exit\n");
    return 0;
}

static void first_module_exit(void)
{
    printk("first_module_exit: entry\n");
    proc_remove(proc_entry);
    printk("first_module_exit: exit\n");
}



module_init(first_module_init);
module_exit(first_module_exit);