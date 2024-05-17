#include <linux/init.h>      /* __init and __exit macroses */
#include <linux/kernel.h>    /* KERN_INFO macros */
#include <linux/module.h>    /* required for all kernel modules */


static int __init hello_init(void)
{
    printk("hello install\n");
    return 0;
}

static void __exit hello_exit(void)
{

    printk("hello uninstall\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("hello Debug Module");
