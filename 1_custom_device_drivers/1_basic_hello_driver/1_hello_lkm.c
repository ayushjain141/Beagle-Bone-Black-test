#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_init(void)
{
printk( KERN_INFO "This is basic_hello_lkm\n" );
return 0;

}

static void __exit hello_exit(void)
{
printk(KERN_INFO "basic_hello_lkm ends here\n");
}


module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Greeting module");
MODULE_AUTHOR("Ayush Jain");



