#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>

//判断一个IO是否合法：
int gpio_is_valid(int number)
{
    ;
}

//设置GPIO的方向，如果是输出同时设置电平：
/* set as input or output, returning 0 or negative errno */
int gpio_direction_input(unsigned gpio)
{
    ;
}
int gpio_direction_output(unsigned gpio, int value)
{
    ;
}

//获取输入引脚的电平：
/* GPIO INPUT: return zero or nonzero */
int gpio_get_value(unsigned gpio)
{
    ;
}

/* GPIO OUTPUT */
void gpio_set_value(unsigned gpio, int value)
{
    ;
}
int gpio_cansleep(unsigned gpio)
{

}
/* GPIO INPUT: return zero or nonzero, might sleep */
int gpio_get_value_cansleep(unsigned gpio)
{
    ;
}
/* GPIO OUTPUT, might sleep */
void gpio_set_value_cansleep(unsigned gpio, int value)
{
    ;
}

//获取一个GPIO并声明标签：
/* request GPIO, returning 0 or negative errno.
 * non-null labels may be useful for diagnostics.
 */
int gpio_request(unsigned gpio, const char *label)
{
    ;
}

/* release previously-claimed GPIO */
void gpio_free(unsigned gpio)
{
    ;
}

//将GPIO映射为IRQ中断：
/* map GPIO numbers to IRQ numbers */
int gpio_to_irq(unsigned gpio)
{
    ;
}

/* map IRQ numbers to GPIO numbers (avoid using this) */
int irq_to_gpio(unsigned irq)
{
    ;
}

//设置GPIO的IRQ中断类型：

/*
if (!sw->both_edges)
{
    if (gpio_get_value(sw->gpio))
    {
        set_irq_type(gpio_to_irq(sw->gpio), IRQ_TYPE_EDGE_FALLING);
    }
    else
    {
        set_irq_type(gpio_to_irq(sw->gpio), IRQ_TYPE_EDGE_RISING);
    }
}
*/
//int main(int argc,char *argv[])

//static inline int of_get_named_gpio(struct device_node *np,const char *propname, int index)
int get_gpio_value()
{
    int index = 0;
    device_node *node;
    int gpio = of_get_named_gpio(node, "reset-gpios", index);
    printf("gpio = %d\n",gpio);
    return 0;
}
