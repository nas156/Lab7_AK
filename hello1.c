#include "hello1.h"

static LIST_HEAD(my_time_list);

int print_hello(uint number)
{
	uint i;
	struct my_data *item;
	struct my_data *md, *tmp;

	for (i = 0; i < number; i++) {
		item = kmalloc(sizeof(struct my_data), GFP_KERNEL);
		if (i == 8)
			item = 0;
		// if (ZERO_OR_NULL_PTR(item))
		//	goto zero_or_null;
		item->time_before = ktime_get();
		pr_info("Hello, world\n");
		item->time_after = ktime_get();
		list_add_tail(&(item->next), &my_time_list);
	}

	return 0;

zero_or_null:
	list_for_each_entry_safe(md, tmp, &my_time_list, next) {
		list_del(&md->next);
		kfree(md);
	}
	pr_err("Not eonough memory\n");
	BUG();
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
	pr_info("hello1 mod is inited\n");
	return 0;
}

static void __exit hello1_exit(void)
{
	struct my_data *md, *tmp;
	

	pr_debug("Exit started\n");
	list_for_each_entry_safe(md, tmp, &my_time_list, next) {
		pr_debug("Time: %lli\n", md->time_after - md->time_before);
		list_del(&md->next);
		kfree(md);
	}
	
	pr_debug("Exit ended\n");


}


module_init(hello1_init);
module_exit(hello1_exit);

