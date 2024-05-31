#include <linux/init.h>     /* __init and __exit macross */
#include <linux/kernel.h>   /* KERN_INFO macros */  
#include <linux/module.h>   /* required for all kernel modules */

static int __init hello_init(void)
{
    printk("hello world by dmy's program hello_test\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk("hello by program hello_test, before uninstall,goodbye~\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("hello Debug Module");