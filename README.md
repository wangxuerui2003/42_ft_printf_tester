# 42kl_ft_printf_tester (for Mac only)

### I want to thank paulo-santana here, who inspired me to create this tester.

## Advice
Try not to use the tester if you are submitting the project for the first time. Try make your own tests, it doesn't have to be automatic but at least try to be familiar with all the output logic of printf (especially the bonus ones), don't just blindly follow the tester's result, you may see how important is this when you start doing the project **get_next_line**.

-----------------

### What I have learned by making this tester
* fork
* pipes
* signal handling
* uses of macros
* how to write a README file
* some more about Makefile

All these are actually benefits that you may not see in a short while (maybe it is if you are gonna start pipex after ft_printf xD) but after all, (heard from others) you are going to have to learn all these when you start doing minishell. So go ahead, make your own tester!

-----------------

### The mechanism of the tester
Your result of `ft_printf` would be compared with the system's `printf` function and will output the comparison between yours and system's if there is any difference.

The tester is able to check **Segmentation faults**, **SigAbort**, **Memory leaks**, and **Timeout**.

-----------------

### RTFM
Clone the repository wherever you want and change the `LIBFTPRINTF_DIR` to the relative path of your `ft_printf` directory.

And in the repository, run:
* `sh start`: run all the tests
* `sh start m`: run all the mandatory tests
* `sh start b`: run all the bonus tests
* `sh start s`: run all the 's' category tests, `cspdiuxX%` are all supported.
* `sh start 42`: run the 42th test only

## Bonus scene
Install python3 if you don't have and run the following commands in your terminal:
* sh bonus_scene
* Try making a compilation error

To my friend Sean (another contributor to this tester)