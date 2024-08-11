#include<linux/init.h>
#include<linux/module.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL"); //*
MODULE_AUTHOR("Nitish"); //!
MODULE_DESCRIPTION("Creates entry under proc directory!"); //!

//Taken from proc_fs.h header file
struct proc_dir_entry *proc_entry;

//input parameters are provided by kernel when read operation is performed while calling this function
static ssize_t firstmod_read(struct file *file_pointer, char *user_space_buffer, size_t count, loff_t * offset)
{
    //prints in the kernel buffer
    printk("firstmod_read: entry\n");

    char msg[] = "ACK!\n";
    size_t len = strlen(msg);
    int result;
    
    //to avoid multiple calls by cat (cat starts reading from offset value)
    if(*offset >= len)
        return 0;
    
    result = copy_to_user(user_space_buffer, msg, len);
    *offset += len;

    //return number of bytes to read to usespace
    return len;
}

struct proc_ops firstmod_proc_ops = {
    .proc_read = firstmod_read
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