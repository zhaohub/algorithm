#include <linux/init.h>
#include <linux/module.h>

#include <linux/kernel.h>

MODULE_LICENSE("GPL");

static int hello_init(void)
{

    printk(KERN_ALERT"hello,I am edsionte\n");
    return 0;
}


static void hello_exit(void)
{

    printk(KERN_ALERT"goodbye,kernel\n");

}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Mr zhao");
MODULE_DESCRIPTION("This is a simple example\n");

MODULE_ALIAS("A simple example");