/** taken from mainline kernel driver for RPR-0521 */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/i2c.h>
#include <linux/regmap.h>
#include <linux/delay.h>
#include <linux/acpi.h>
#include <linux/iio/iio.h>
#include <linux/iio/sysfs.h>
#include <linux/pm_runtime.h>

/** these headers are taken from xilinx github repository may be hardware specific */

/*
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/err.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/platform_data/i2c-xiic.h>
#include <linux/io.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/clk.h>
#include <linux/pm_runtime.h>
*/

MODULE_LICENSE("GPL");            ///< The license type -- this affects available functionality
MODULE_AUTHOR("Ayush Jain");    ///< The author -- visible when you use modinfo
MODULE_DESCRIPTION("RPR-0521 sensor i2c driver");///< The description--see modinfo
MODULE_VERSION("0.1");            ///< A version number to inform users

static int     dev_open(struct inode *, struct file *);
static int     dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

/** sensor address  */
#define SENSOR_ADDR 		0x38
/** register address  */
#define SYS_CTRL_REG_		0x40       
#define MODE_CTRL_REG		0x41
#define ALS_DATA_LSB_REG	0x46

/** sensor commands   */
#define SENSOR_CMD   	 	0x80

/** essentials for i2c hardware */
struct i2c_client *client;

/** sensor info structure */
static struct sensor_info
{
static int sensor_data[2];
}; 




