#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/ktime.h>
#include <linux/slab.h>

MODULE_AUTHOR("Nazar Hevelencko <gevelencko8@gmail.com>");
MODULE_DESCRIPTION("Lab-7 advanced task implementation");
MODULE_LICENSE("Dual BSD/GPL");

extern int print_hello(uint number);

struct my_data {
	struct list_head next;
	ktime_t time_before;
	ktime_t time_after;
};


