/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:51:24 by wxuerui           #+#    #+#             */
/*   Updated: 2022/07/24 13:12:06 by wxuerui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_header.h"

static void	describe(char *str)
{
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}

void	run_test(t_flags *flags, t_status *status)
{
	char *null_str = NULL;

	describe("basic test");
	flags->should_test = 1;

	TEST(status, should_test(flags, status), ("1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest"));

	flags->should_test = flags->c;
	if (flags->should_test)
		describe("\n%c basic");

	TEST(status, should_test(flags, status), ("%c", 'a'));
	TEST(status, should_test(flags, status), ("%c%c%c*", '\0', '1', 1));
	TEST(status, should_test(flags, status), ("%c small string", 'a'));
	TEST(status, should_test(flags, status), ("%c small string", '\0'));
	TEST(status, should_test(flags, status), ("the char is: %c", 'a'));
	TEST(status, should_test(flags, status), ("the char is: %c", '\0'));
	TEST(status, should_test(flags, status), ("n%cs", 'a'));
	TEST(status, should_test(flags, status), ("%c%c%c%c%c", 'a', 'i', 'u', 'e', 'o'));
	TEST(status, should_test(flags, status), ("l%cl%cl%cl%cl%c", 'a', 'i', 'u', 'e', 'o'));
	TEST(status, should_test(flags, status), ("l%cl%cl%cl%cl%c", '\0', '\0', '\0', 'e', '\0'));

	flags->should_test = flags->s;
	if (flags->should_test)
		describe("\n%s basic");

	TEST(status, should_test(flags, status), ("%s", ""));
	TEST(status, should_test(flags, status), ("this is a %s", "test"));
	TEST(status, should_test(flags, status), ("this is 1 %s with %s %s", "test", "multiple", "strings"));
	TEST(status, should_test(flags, status), ("%s%s%s%s", "This ", "is", " an ugly ", "test"));
	TEST(status, should_test(flags, status), ("%s", "This is a rather simple test."));
	TEST(status, should_test(flags, status), ("%s", "-2"));
	TEST(status, should_test(flags, status), ("%s", "-24"));
	TEST(status, should_test(flags, status), ("%s", "-stop"));
	TEST(status, should_test(flags, status), ("%s", "-0003"));
	TEST(status, should_test(flags, status), ("%s", "000-0003"));
	TEST(status, should_test(flags, status), ("%s", "0x42"));
	TEST(status, should_test(flags, status), ("%s", "0x0000042"));
	TEST(status, should_test(flags, status), ("some naugty tests: %s", "0000%"));
	TEST(status, should_test(flags, status), ("some naugty tests: %s", "    %"));
	TEST(status, should_test(flags, status), ("some naugty tests: %s", "%000"));
	TEST(status, should_test(flags, status), ("%s", "bea thought but bea forgot the loop that the chars cause she was floaty during the amsterdam siren call. she got me by surprise you probably read my mind that look in your eyes and judging by your own cries you probably read my mind this is a really long string and if you see this you must look at your return values!kthxbai this must have more than 127 chars by now isnt it ok 4242 4 life 1337 code everyday to the moon!"));
	TEST(status, should_test(flags, status), ("%s", null_str));
	TEST(status, should_test(flags, status), ("%s everywhere", null_str));
	TEST(status, should_test(flags, status), ("everywhere %s", null_str));
	TEST(status, should_test(flags, status), ("%s", "h"));
	TEST(status, should_test(flags, status), ("t%st%s", "a", "u"));
	TEST(status, should_test(flags, status), ("%s%s%s%s%s%s", "a", "i", "u", "e", "o", "l"));

	flags->should_test = flags->p;
	if (flags->should_test)
		describe("\n%p basic");

	int test = 42;
	TEST(status, should_test(flags, status), ("%p", &test));
	TEST(status, should_test(flags, status), ("%p is a virtual memory address", &test));
	TEST(status, should_test(flags, status), ("The address of the answer is %p", &test));
	TEST(status, should_test(flags, status), ("The address is %p, so what?", &test));
	int *ptr = &test;
	TEST(status, should_test(flags, status), ("A pointer at %p points to %p", &test, &ptr));
	TEST(status, should_test(flags, status), ("This %p is a very strange address", (void *)(long int)test));

	char *mallocked = malloc(2);
	TEST(status, should_test(flags, status), ("This %p is an address from the heap", mallocked); free(mallocked);); free(mallocked);
	TEST(status, should_test(flags, status), ("%p", NULL));
	TEST(status, should_test(flags, status), ("The NULL macro represents the %p address", NULL));
	TEST(status, should_test(flags, status), ("This %p is even stranger", (void *)-1));

	flags->should_test = flags->d;
	if (flags->should_test)
		describe("\n%d basic");

	TEST(status, should_test(flags, status), ("%d", 0));
	TEST(status, should_test(flags, status), ("%d", 10));
	TEST(status, should_test(flags, status), ("%d, %d", 10, 20));
	TEST(status, should_test(flags, status), ("%d%d%d%d", 10, 20, 30, 5));
	TEST(status, should_test(flags, status), ("%d %d", 2147483647, (int)-2147483648));
	TEST(status, should_test(flags, status), ("42 - 84 is %d", -42));
	TEST(status, should_test(flags, status), ("%d C is the lowest temperature in the universe", -273));
	TEST(status, should_test(flags, status), ("%dxC is the lowest temperature in the universe", -273));
	TEST(status, should_test(flags, status), ("%dsC is the lowest temperature in the universe", -273));
	TEST(status, should_test(flags, status), ("%dpC is the lowest temperature in the universe", -273));

	flags->should_test = flags->i;
	if (flags->should_test)
		describe("\n%i basic");

	TEST(status, should_test(flags, status), ("%i", 0));
	TEST(status, should_test(flags, status), ("%i", 10));
	TEST(status, should_test(flags, status), ("%i, %i", 10, 23));
	TEST(status, should_test(flags, status), ("%i%i%i%i%i%i%i", 10, 23, -2, 37, 200, -9999, 977779));
	TEST(status, should_test(flags, status), ("%i %i", 2147483647, (int)-2147483648));
	TEST(status, should_test(flags, status), ("%iq%i", 21447, -21648));

	flags->should_test = flags->u;
	if (flags->should_test)
		describe("\n%u basic");

	TEST(status, should_test(flags, status), ("%u", 42));
	TEST(status, should_test(flags, status), ("%u", 0));
	TEST(status, should_test(flags, status), ("%u", 2147483647));
	TEST(status, should_test(flags, status), ("%u", (unsigned int)2147483648));
	TEST(status, should_test(flags, status), ("%u", (unsigned int)3147983649));
	TEST(status, should_test(flags, status), ("%u", (unsigned int)4294967295));
	TEST(status, should_test(flags, status), ("%u to the power of %u is %u", 2, 32, (unsigned int)4294967295));
	TEST(status, should_test(flags, status), ("%u%u%u%u", (unsigned int)429896724, 0, 32, (unsigned int)4294967295));

	flags->should_test = flags->x;
	if (flags->should_test)
		describe("\n%x basic");

	TEST(status, should_test(flags, status), ("%x", 0));
	TEST(status, should_test(flags, status), ("%x", 1));
	TEST(status, should_test(flags, status), ("%x", 10));
	TEST(status, should_test(flags, status), ("%x", 16));
	TEST(status, should_test(flags, status), ("%x", 160));
	TEST(status, should_test(flags, status), ("%x", 255));
	TEST(status, should_test(flags, status), ("%x", 256));
	TEST(status, should_test(flags, status), ("%x", 3735929054u));
	TEST(status, should_test(flags, status), ("the password is %x", 3735929054u));
	TEST(status, should_test(flags, status), ("%x is the definitive answer", 66u));
	TEST(status, should_test(flags, status), ("this is the real number: %x", -1u));

	flags->should_test = flags->X;
	if (flags->should_test)
		describe("\n%X basic");

	TEST(status, should_test(flags, status), ("%X", 0));
	TEST(status, should_test(flags, status), ("%X", 1));
	TEST(status, should_test(flags, status), ("%X", 10));
	TEST(status, should_test(flags, status), ("%X", 16));
	TEST(status, should_test(flags, status), ("%X", 160));
	TEST(status, should_test(flags, status), ("%X", 255));
	TEST(status, should_test(flags, status), ("%X", 256));
	TEST(status, should_test(flags, status), ("%X", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("the password is %X", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("%X is the definitive answer", (unsigned int)66));
	TEST(status, should_test(flags, status), ("this is the real number: %X", (unsigned int)-1));

	flags->should_test = flags->percent;
	if (flags->should_test)
		describe("\n%% basic");

	TEST(status, should_test(flags, status), ("%%"));
	TEST(status, should_test(flags, status), ("100%%"));
	TEST(status, should_test(flags, status), ("%%p is how you print a pointer in printf"));
	TEST(status, should_test(flags, status), ("the '%%%%' is used to print a %% in printf"));
	TEST(status, should_test(flags, status), ("%%%%%%%%%%%%%%%%"));
	TEST(status, should_test(flags, status), ("%%c%%s%%p%%d%%i%%u%%x%%X%%"));

	flags->should_test = flags->c && flags->s && flags->p && flags->d && flags->i && flags->x && flags->X && flags->percent;
	if (flags->should_test)
		describe("\nmix");

	TEST(status, should_test(flags, status), ("%c - %s - %p %d - %i - %u - %x %X %%", 'a', "test", (void *)0xdeadc0de, 20, -20, -1, -1, 200000000));
	TEST(status, should_test(flags, status), ("%c - %s - %p %d - %i - %u - %x %X %%", '\0', "test", (void *)-1, 20, -20, -1, -1, 200000000));
	TEST(status, should_test(flags, status), ("%c - %s - %p %d - %i - %u - %x %X %%", 'c', "", (void *)-1, 20, -20, -1, -1, 200000000));
	TEST(status, should_test(flags, status), ("%i - %s - %p %d - %c - %u - %x %X %%", 20, "", (void *)-1, '\0', -20, -1, -1, 200000000));
	TEST(status, should_test(flags, status), ("%c - %s - %p %d - %i - %u - %x %X %%", 'b', null_str, NULL, 20, -20, -1, -1, 200000000));
	TEST(status, should_test(flags, status), ("%c %s - %p - %d - %i %u - %x - %X %%", '\0', null_str, (void *)0xdeadc0de, 0, (int)-2147483648, -1, -1, 200000000));

	if (flags->bonus == 0)
		return ;

	flags->should_test = flags->c;
	if (flags->should_test)
		describe("\n%c and widths");

	TEST(status, should_test(flags, status), ("%1c", 'a'));
	TEST(status, should_test(flags, status), ("%1c", '\0'));
	TEST(status, should_test(flags, status), ("%10c", 'b'));
	TEST(status, should_test(flags, status), ("%10c", '\0'));
	TEST(status, should_test(flags, status), ("%2c", 'c'));
	TEST(status, should_test(flags, status), ("there are 15 spaces between this text and the next char%15c", 'd'));
	TEST(status, should_test(flags, status), ("%5chis paragraph is indented", 't'));
	TEST(status, should_test(flags, status), ("%5c now you see", '\0'));
	TEST(status, should_test(flags, status), ("The number %7c represents luck", '7'));

	flags->should_test = flags->s;
	if (flags->should_test)
		describe("\n%s and widths");

	TEST(status, should_test(flags, status), ("%1s", "a"));
	TEST(status, should_test(flags, status), ("%1s", "abc"));
	TEST(status, should_test(flags, status), ("%7s", "a"));
	TEST(status, should_test(flags, status), ("%7s", "abc"));
	TEST(status, should_test(flags, status), ("%1s", "-42"));
	TEST(status, should_test(flags, status), ("%2s", "-42"));
	TEST(status, should_test(flags, status), ("%3s", "-42"));
	TEST(status, should_test(flags, status), ("%4s", "-42"));
	TEST(status, should_test(flags, status), ("%5s", "-42"));
	TEST(status, should_test(flags, status), ("%6s", "-42"));
	TEST(status, should_test(flags, status), ("%1s", null_str));
	TEST(status, should_test(flags, status), ("%2s", null_str));
	TEST(status, should_test(flags, status), ("%5s", null_str));
	TEST(status, should_test(flags, status), ("%6s", null_str));
	TEST(status, should_test(flags, status), ("%7s", null_str));
	TEST(status, should_test(flags, status), ("%7s is as easy as %13s", "abc", "123"));
	TEST(status, should_test(flags, status), ("%13s are the three first letter of the %3s", "a, b and c", "alphabet"));
	TEST(status, should_test(flags, status), ("%s%13s%42s%3s", "a, b and c", " are letters", " of the", " alphabet"));
	TEST(status, should_test(flags, status), ("%sc%13sd%42sp%3sx", "a, b and c", " are letters", " of the", " alphabet"));
	TEST(status, should_test(flags, status), ("%sc%13sd%42sp%3sx", "a, b and c", " are letters", " of the", " alphabet"));

	flags->should_test = flags->p;
	if (flags->should_test)
		describe("\n%p and widths");

	char c;
	TEST(status, should_test(flags, status), ("%1p", &c));
	TEST(status, should_test(flags, status), ("%30p", &c));
	TEST(status, should_test(flags, status), ("%12p", (void *)0x7ffe6b8e60c6));
	TEST(status, should_test(flags, status), ("%13p", (void *)0x7ffe6b8e60c5));
	TEST(status, should_test(flags, status), ("%14p", (void *)0x7ffe6b8e60c4));
	TEST(status, should_test(flags, status), ("the address is %12p", (void *)0x7ffe6b8e60c7));
	TEST(status, should_test(flags, status), ("the address is %13p", (void *)0x7ffe6b8e60c8));
	TEST(status, should_test(flags, status), ("the address is %14p", (void *)0x7ffe6b8e60c9));
	TEST(status, should_test(flags, status), ("the address is %1p", (void *)0));
	TEST(status, should_test(flags, status), ("the address is %2p", (void *)0));
	TEST(status, should_test(flags, status), ("the address is %3p", (void *)0));
	TEST(status, should_test(flags, status), ("the address is %4p", (void *)0));
	TEST(status, should_test(flags, status), ("the address is %8p", (void *)0));
	TEST(status, should_test(flags, status), ("%12p is the address", (void *)0x7ffe6b8e60c7));
	TEST(status, should_test(flags, status), ("%13p is the address", (void *)0x7ffe6b8e60c8));
	TEST(status, should_test(flags, status), ("%14p is the address", (void *)0x7ffe6b8e60c9));
	TEST(status, should_test(flags, status), ("%1p is the address", (void *)0));
	TEST(status, should_test(flags, status), ("%2p is the address", (void *)0));
	TEST(status, should_test(flags, status), ("%3p is the address", (void *)0));
	TEST(status, should_test(flags, status), ("%4p is the address", (void *)0));
	TEST(status, should_test(flags, status), ("%8p is the address", (void *)0));

	flags->should_test = flags->d;
	if (flags->should_test)
		describe("\n%d and widths");

	TEST(status, should_test(flags, status), ("%1d", 0));
	TEST(status, should_test(flags, status), ("%1d", -4));
	TEST(status, should_test(flags, status), ("%10d", 42));
	TEST(status, should_test(flags, status), ("%42d", 42000));
	TEST(status, should_test(flags, status), ("%20d", -42000));
	TEST(status, should_test(flags, status), ("wait for it... %50d", 42));
	TEST(status, should_test(flags, status), ("%20d is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%5d", 2147483647));
	TEST(status, should_test(flags, status), ("%30d", 2147483647));
	TEST(status, should_test(flags, status), ("%10d", 2147483647));
	TEST(status, should_test(flags, status), ("%5d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%30d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%10d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%11d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%12d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%12d, %20d, %2d, %42d", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%12d, %d, %2d, %42d", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%14d%20d%2d%d", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%14dc%20ds%2dx%du", (int)-2147483648, 3, 30, -1));

	flags->should_test = flags->i;
	if (flags->should_test)
		describe("\n%i and widths");

	TEST(status, should_test(flags, status), ("%1i", 0));
	TEST(status, should_test(flags, status), ("%1i", -4));
	TEST(status, should_test(flags, status), ("%10i", 42));
	TEST(status, should_test(flags, status), ("%42i", 42000));
	TEST(status, should_test(flags, status), ("%20i", -42000));
	TEST(status, should_test(flags, status), ("wait for it... %50i", 42));
	TEST(status, should_test(flags, status), ("%20i is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%5i", 2147483647));
	TEST(status, should_test(flags, status), ("%30i", 2147483647));
	TEST(status, should_test(flags, status), ("%10i", 2147483647));
	TEST(status, should_test(flags, status), ("%5i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%30i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%10i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%11i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%12i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%12i, %20i, %2i, %42i", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%12i, %i, %2i, %42i", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%14i%20i%2i%i", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%14ic%20is%2ix%du", (int)-2147483648, 3, 30, -1));

	flags->should_test = flags->u;
	if (flags->should_test)
		describe("\n%u and widths");

	TEST(status, should_test(flags, status), ("%1u", 0));
	TEST(status, should_test(flags, status), ("%2u", 1));
	TEST(status, should_test(flags, status), ("%1u", 1000));
	TEST(status, should_test(flags, status), ("%4u", 1000));
	TEST(status, should_test(flags, status), ("%30u", 1000));
	TEST(status, should_test(flags, status), ("%9u is the biggest unsigned int", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%10uis the biggest unsigned int", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%11uis the biggest unsigned int", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the biggest unsigned int is %9u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the biggest unsigned int is %10u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the biggest unsigned int is %11u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("Here are some numbers: %1u%2u%5u%3u%9u and %ui", 11, (unsigned int)-1, 2, 200, 3, 10));

	flags->should_test = flags->x;
	if (flags->should_test)
		describe("\n%x and widths");

	TEST(status, should_test(flags, status), ("%1x", 0));
	TEST(status, should_test(flags, status), ("%2x", 1));
	TEST(status, should_test(flags, status), ("%3x", 10));
	TEST(status, should_test(flags, status), ("%1x", 16));
	TEST(status, should_test(flags, status), ("%2x", 160));
	TEST(status, should_test(flags, status), ("%3x", 255));
	TEST(status, should_test(flags, status), ("%42x", 256));
	TEST(status, should_test(flags, status), ("%7x", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("%8x", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("%9x", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("the password is %7x", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("the password is %8x", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("the password is %9x", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("%1x is the definitive answer", (unsigned int)66));
	TEST(status, should_test(flags, status), ("%2x is the definitive answer", (unsigned int)66));
	TEST(status, should_test(flags, status), ("%3x is the definitive answer", (unsigned int)66));
	TEST(status, should_test(flags, status), ("this is the real number: %7x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("this is the real number: %8x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("this is the real number: %9x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%1x%2x%9x", (unsigned int)-1, 0xf0ca, 123456));
	TEST(status, should_test(flags, status), ("%1xis doomed%2xpost%9xX args", (unsigned int)-1, 0xf0b1a, 7654321));

	flags->should_test = flags->X;
	if (flags->should_test)
		describe("\n%X and widths");

	TEST(status, should_test(flags, status), ("%1X", 0));
	TEST(status, should_test(flags, status), ("%2X", 1));
	TEST(status, should_test(flags, status), ("%3X", 10));
	TEST(status, should_test(flags, status), ("%1X", 16));
	TEST(status, should_test(flags, status), ("%2X", 160));
	TEST(status, should_test(flags, status), ("%3X", 255));
	TEST(status, should_test(flags, status), ("%42X", 256));
	TEST(status, should_test(flags, status), ("%7X", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("%8X", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("%9X", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("the password is %7X", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("the password is %8X", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("the password is %9X", (unsigned int)3735929054));
	TEST(status, should_test(flags, status), ("%1X is the definitive answer", (unsigned int)66));
	TEST(status, should_test(flags, status), ("%2X is the definitive answer", (unsigned int)66));
	TEST(status, should_test(flags, status), ("%3X is the definitive answer", (unsigned int)66));
	TEST(status, should_test(flags, status), ("this is the real number: %7X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("this is the real number: %8X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("this is the real number: %9X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%1X%2X%9X", (unsigned int)-1, 0xf0ca, 123456));
	TEST(status, should_test(flags, status), ("%1Xis doomed%2Xpost%9Xx args", (unsigned int)-1, 0xf0b1a, 7654321));

	flags->should_test = flags->s;
	if (flags->should_test)
		describe("\n%s and precisions");

	TEST(status, should_test(flags, status), ("%.s", "hi there"));
	TEST(status, should_test(flags, status), ("%.0s", "hi there"));
	TEST(status, should_test(flags, status), ("%.1s", "hi there"));
	TEST(status, should_test(flags, status), ("%.2s", "hi there"));
	TEST(status, should_test(flags, status), ("%.3s", "hi there"));
	TEST(status, should_test(flags, status), ("%.4s", "hi there"));
	TEST(status, should_test(flags, status), ("%.7s", "hi there"));
	TEST(status, should_test(flags, status), ("%.8s", "hi there"));
	TEST(status, should_test(flags, status), ("%.9s", "hi there"));
	TEST(status, should_test(flags, status), ("%.12s", "hi there"));
	TEST(status, should_test(flags, status), ("%.s", "-42"));
	TEST(status, should_test(flags, status), ("%.0s", "-42"));
	TEST(status, should_test(flags, status), ("%.1s", "-42"));
	TEST(status, should_test(flags, status), ("%.2s", "-42"));
	TEST(status, should_test(flags, status), ("%.3s", "-42"));
	TEST(status, should_test(flags, status), ("%.4s", "-42"));
	TEST(status, should_test(flags, status), ("%.7s", "-42"));
	TEST(status, should_test(flags, status), ("%.1s", null_str));
	TEST(status, should_test(flags, status), ("%.2s", null_str));
	TEST(status, should_test(flags, status), ("%.5s", null_str));
	TEST(status, should_test(flags, status), ("%.6s", null_str));
	TEST(status, should_test(flags, status), ("%.7s", null_str));
	TEST(status, should_test(flags, status), ("%.2s, motherfucker", "hi there"));
	TEST(status, should_test(flags, status), ("This %.3s a triumph ", "wasabi"));
	TEST(status, should_test(flags, status), ("%.4s making a %.4s here: %.13s", "I'm delighted", "notation", "HUGE SUCCESS!"));
	TEST(status, should_test(flags, status), ("It's %.4s to over%.50s my%s", "hardware", "state", " satisfaction"));
	TEST(status, should_test(flags, status), ("%.11s%.6s%.4s", "Aperture", " Scientists", "ce"));
	TEST(status, should_test(flags, status), ("%1.s", "21-school.ru"));
	TEST(status, should_test(flags, status), ("%10.1s", "21-school.ru"));

	flags->should_test = flags->d;
	if (flags->should_test)
		describe("\n%d and precisions");

	TEST(status, should_test(flags, status), ("%.1d", 2));
	TEST(status, should_test(flags, status), ("%.2d", 3));
	TEST(status, should_test(flags, status), ("%.4d", 32));
	TEST(status, should_test(flags, status), ("%.3d", 420000));
	TEST(status, should_test(flags, status), ("%.0d", 420000));
	TEST(status, should_test(flags, status), ("%.3d", -1));
	TEST(status, should_test(flags, status), ("%.3d", -1234));
	TEST(status, should_test(flags, status), ("%.4d", -1234));
	TEST(status, should_test(flags, status), ("%.5d", -1234));
	TEST(status, should_test(flags, status), ("%.5d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.9d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.10d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.11d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.12d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.13d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.5d", 2147483647));
	TEST(status, should_test(flags, status), ("%.9d", 2147483647));
	TEST(status, should_test(flags, status), ("%.10d", 2147483647));
	TEST(status, should_test(flags, status), ("%.11d", 2147483647));
	TEST(status, should_test(flags, status), ("%.12d", 2147483647));
	TEST(status, should_test(flags, status), ("%.0d", 2));
	TEST(status, should_test(flags, status), ("%.0d", 2147483647));
	TEST(status, should_test(flags, status), ("%.0d", 0));
	TEST(status, should_test(flags, status), ("%.0d", 10));
	TEST(status, should_test(flags, status), ("%.d", 10));
	TEST(status, should_test(flags, status), ("%.d", 0));
	TEST(status, should_test(flags, status), ("I'm gonna watch %.3d", 7));
	TEST(status, should_test(flags, status), ("%.3d is the movie I'm gonna watch", 7));
	TEST(status, should_test(flags, status), ("Then take these %.7d things and get the hell out of here", 2));
	TEST(status, should_test(flags, status), ("Bla %.2di bla %.5dsbla bla %.dx bla %.d", 127, 42, 1023, 0));
	TEST(status, should_test(flags, status), ("%.4d%.2d%.20d%.0d%.0d%.d%.d%.d", 127, 0, 1023, 0, (int)-2147483648, 0, 1, (int)-2147483648));

	flags->should_test = flags->i;
	if (flags->should_test)
		describe("\n%i and precisions");

	TEST(status, should_test(flags, status), ("%.1i", 7));
	TEST(status, should_test(flags, status), ("%.3i", 7));
	TEST(status, should_test(flags, status), ("%.2i", 3));
	TEST(status, should_test(flags, status), ("%.4i", 32));
	TEST(status, should_test(flags, status), ("%.3i", 420000));
	TEST(status, should_test(flags, status), ("%.0i", 420000));
	TEST(status, should_test(flags, status), ("%.3i", -1));
	TEST(status, should_test(flags, status), ("%.3i", -1234));
	TEST(status, should_test(flags, status), ("%.4i", -1234));
	TEST(status, should_test(flags, status), ("%.5i", -1234));
	TEST(status, should_test(flags, status), ("%.5i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.9i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.10i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.11i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.12i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.13i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%.5i", 2147483647));
	TEST(status, should_test(flags, status), ("%.9i", 2147483647));
	TEST(status, should_test(flags, status), ("%.10i", 2147483647));
	TEST(status, should_test(flags, status), ("%.11i", 2147483647));
	TEST(status, should_test(flags, status), ("%.12i", 2147483647));
	TEST(status, should_test(flags, status), ("%.0i", 2));
	TEST(status, should_test(flags, status), ("%.0i", 2147483647));
	TEST(status, should_test(flags, status), ("%.0i", 0));
	TEST(status, should_test(flags, status), ("%.0i", 10));
	TEST(status, should_test(flags, status), ("%.i", 10));
	TEST(status, should_test(flags, status), ("%.i", 0));
	TEST(status, should_test(flags, status), ("I'm gonna watch %.3i", 7));
	TEST(status, should_test(flags, status), ("%.3i is the movie I'm gonna watch", 7));
	TEST(status, should_test(flags, status), ("Then take these %.7i things and get the hell out of here", 2));
	TEST(status, should_test(flags, status), ("Bla %.2ii bla %.5isbla bla %.ix bla %.i", 127, 42, 1023, 0));
	TEST(status, should_test(flags, status), ("%.4i%.2i%.20i%.0i%.0i%.i%.i%.i", 127, 0, 1023, 0, (int)-2147483648, 0, 1, (int)-2147483648));

	flags->should_test = flags->u;
	if (flags->should_test)
		describe("\n%u and precisions");

	TEST(status, should_test(flags, status), ("%.1u", 1));
	TEST(status, should_test(flags, status), ("%.2u", 1));
	TEST(status, should_test(flags, status), ("%.2u", 0));
	TEST(status, should_test(flags, status), ("%.0u", 0));
	TEST(status, should_test(flags, status), ("%.u", 0));
	TEST(status, should_test(flags, status), ("%.2u", 30000));
	TEST(status, should_test(flags, status), ("%.20u", 30000));
	TEST(status, should_test(flags, status), ("%.0u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.5u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.9u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.10u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.11u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.10uis a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.0uis a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.4us a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.9uxs a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.11ups a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.0u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.5u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.9u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.10u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.11u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.11u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.0uis a big number", 0));
	TEST(status, should_test(flags, status), ("%.4us a big number", 0));
	TEST(status, should_test(flags, status), ("the number is %.0u", 0));
	TEST(status, should_test(flags, status), ("the number is %.u", 0));
	TEST(status, should_test(flags, status), ("the number is %.5u", 0));
	TEST(status, should_test(flags, status), ("%u%.5u%.0u%.u%.9u", 5, 55, 2, 0, 42));
	TEST(status, should_test(flags, status), ("%us%.5ui%.0uc%.up%.9ux", 5, 55, 2, 0, 42));

	flags->should_test = flags->x;
	if (flags->should_test)
		describe("\n%x and precisions");

	TEST(status, should_test(flags, status), ("%.1x", 0xa));
	TEST(status, should_test(flags, status), ("%.4x", 11));
	TEST(status, should_test(flags, status), ("%.0x", 0));
	TEST(status, should_test(flags, status), ("%.1x", -1));
	TEST(status, should_test(flags, status), ("%.10x", -1));
	TEST(status, should_test(flags, status), ("%.14x", -1));
	TEST(status, should_test(flags, status), ("%.8x", 0));
	TEST(status, should_test(flags, status), ("%.2x", 30000));
	TEST(status, should_test(flags, status), ("%.20x", 30000));
	TEST(status, should_test(flags, status), ("%.0x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.5x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.9x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.10x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.11x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.10xis a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.0xis a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.4xs a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.9xxs a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.11xps a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.0x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.5x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.9x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.10x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.11x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.11x", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.0xis a big number", 0));
	TEST(status, should_test(flags, status), ("%.4xs a big number", 0));
	TEST(status, should_test(flags, status), ("the number is %.0x", 0));
	TEST(status, should_test(flags, status), ("the number is %.x", 0));
	TEST(status, should_test(flags, status), ("the number is %.5x", 0));
	TEST(status, should_test(flags, status), ("%x%.5x%.0x%.x%.9x", 5, 55, 2, 0, 42));
	TEST(status, should_test(flags, status), ("%xs%.5xi%.0xc%.xp%.9xu", 5, 55, 2, 0, 42));

	flags->should_test = flags->X;
	if (flags->should_test)
		describe("\n%X and precisions");

	TEST(status, should_test(flags, status), ("%.1X", 0xa));
	TEST(status, should_test(flags, status), ("%.4X", 11));
	TEST(status, should_test(flags, status), ("%.0X", 0));
	TEST(status, should_test(flags, status), ("%.1X", -1));
	TEST(status, should_test(flags, status), ("%.10X", -1));
	TEST(status, should_test(flags, status), ("%.14X", -1));
	TEST(status, should_test(flags, status), ("%.8X", 0));
	TEST(status, should_test(flags, status), ("%.2X", 30000));
	TEST(status, should_test(flags, status), ("%.20X", 30000));
	TEST(status, should_test(flags, status), ("%.0X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.5X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.9X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.10X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.11X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.10Xis a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.0Xis a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.4Xs a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.9XXs a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.11Xps a big number", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.0X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.5X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.9X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.10X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.11X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("the number is %.11X", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%.0Xis a big number", 0));
	TEST(status, should_test(flags, status), ("%.4Xs a big number", 0));
	TEST(status, should_test(flags, status), ("the number is %.0X", 0));
	TEST(status, should_test(flags, status), ("the number is %.X", 0));
	TEST(status, should_test(flags, status), ("the number is %.5X", 0));
	TEST(status, should_test(flags, status), ("%X%.5X%.0X%.X%.9X", 5, 55, 2, 0, 42));
	TEST(status, should_test(flags, status), ("%Xs%.5Xi%.0Xc%.Xp%.9Xu", 5, 55, 2, 0, 42));

	flags->should_test = flags->c;
	if (flags->should_test)
		describe("\n%c, widths and -");

	TEST(status, should_test(flags, status), ("%-c", 'p'));
	TEST(status, should_test(flags, status), ("%-1c", 'b'));
	TEST(status, should_test(flags, status), ("%-5c", 'w'));
	TEST(status, should_test(flags, status), (" kk daora%-5cblz", 'w'));
	TEST(status, should_test(flags, status), ("%-20carigatou", 'w'));
	TEST(status, should_test(flags, status), ("%-c%-c%-4c%-11c", 'a', 'b', 'c', 'd'));
	TEST(status, should_test(flags, status), ("%-ci%-cp%4cs%-11cx", 'a', 'b', 'c', 'd'));
	TEST(status, should_test(flags, status), ("%----ci%---cp%4cs%--11cx", 'a', 'b', 'c', 'd'));
	TEST(status, should_test(flags, status), ("%-c%-c%c*", 0, '1', 1));
	TEST(status, should_test(flags, status), ("%-2c%-3c%-4c*", 0, 'a', 0));

	flags->should_test = flags->s;
	if (flags->should_test)
		describe("\n%s, widths, precisions and -");

	TEST(status, should_test(flags, status), ("%-9sScience!", "Aperture"));
	TEST(status, should_test(flags, status), ("We %-s what we %8s, %-2s we %-20s", "do", "must", "because", "can"));
	TEST(status, should_test(flags, status), ("%--4s %s %------------------9s of %s of %-5s", "for", "the", "goooood", "aaall", "us"));
	TEST(status, should_test(flags, status), ("%--4.1s %s %------------------9.3s of %s of %-5.7s", "for", "the", "goooood", "aaall", "us"));
	TEST(status, should_test(flags, status), ("%--.sp--.su kkkk", "pegadinha po"));
	TEST(status, should_test(flags, status), ("%-9sScience!", "-42"));

	flags->should_test = flags->p;
	if (flags->should_test)
		describe("\n%p, widths and -");

	TEST(status, should_test(flags, status), ("that's the way it %-20pis", ""));
	TEST(status, should_test(flags, status), ("as soon as %-10possible", (void *) -1));
	TEST(status, should_test(flags, status), ("as soon as %-16peasible", (void *) (((long int)3 << 42) + 15)));
	TEST(status, should_test(flags, status), ("as soon as %-16peasible", (void *) (((long int)3 << 42) + 15)));
	TEST(status, should_test(flags, status), ("thats %-psrobably not a good idea", (void *) 13));
	TEST(status, should_test(flags, status), ("%------21pwhoa wtf is that", (void *) 13));
	TEST(status, should_test(flags, status), ("%------21p yeah i'm %p running out %--p of ideas", (void *) 13, (void *) 65, (void *) -1));

	flags->should_test = flags->d;
	if (flags->should_test)
		describe("\n%d, widths, precisions and -");

	TEST(status, should_test(flags, status), ("%-d", 0));
	TEST(status, should_test(flags, status), ("%-d", 1));
	TEST(status, should_test(flags, status), ("%-d", 10));
	TEST(status, should_test(flags, status), ("%-d", -10));
	TEST(status, should_test(flags, status), ("%-d", 5000));
	TEST(status, should_test(flags, status), ("%-d", -5000));
	TEST(status, should_test(flags, status), ("%-d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-d", 2147483647));
	TEST(status, should_test(flags, status), ("%-1d", 0));
	TEST(status, should_test(flags, status), ("%-1d", 1));
	TEST(status, should_test(flags, status), ("%-1d", 10));
	TEST(status, should_test(flags, status), ("%-1d", -10));
	TEST(status, should_test(flags, status), ("%-1d", 5000));
	TEST(status, should_test(flags, status), ("%-1d", -5000));
	TEST(status, should_test(flags, status), ("%-1d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-1d", 2147483647));
	TEST(status, should_test(flags, status), ("%-10d", 0));
	TEST(status, should_test(flags, status), ("%-10d", 1));
	TEST(status, should_test(flags, status), ("%-10d", 10));
	TEST(status, should_test(flags, status), ("%-10d", -10));
	TEST(status, should_test(flags, status), ("%-10d", 5000));
	TEST(status, should_test(flags, status), ("%-10d", -5000));
	TEST(status, should_test(flags, status), ("%-10d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-10d", 2147483647));
	TEST(status, should_test(flags, status), ("%-.d", 0));
	TEST(status, should_test(flags, status), ("%-.1d", 1));
	TEST(status, should_test(flags, status), ("%-.2d", 10));
	TEST(status, should_test(flags, status), ("%-.3d", -10));
	TEST(status, should_test(flags, status), ("%-.4d", 5000));
	TEST(status, should_test(flags, status), ("%-.5d", -5000));
	TEST(status, should_test(flags, status), ("%-.6d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-.7d", 2147483647));
	TEST(status, should_test(flags, status), ("%-1.8d", 0));
	TEST(status, should_test(flags, status), ("%-1.9d", 1));
	TEST(status, should_test(flags, status), ("%-1.10d", 10));
	TEST(status, should_test(flags, status), ("%-1.0d", -10));
	TEST(status, should_test(flags, status), ("%-1.6d", 5000));
	TEST(status, should_test(flags, status), ("%-1.4d", -5000));
	TEST(status, should_test(flags, status), ("%-1.10d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-1.12d", 2147483647));
	TEST(status, should_test(flags, status), ("%-10.d", 0));
	TEST(status, should_test(flags, status), ("%-10.10d", 1));
	TEST(status, should_test(flags, status), ("%-10.5d", 10));
	TEST(status, should_test(flags, status), ("%-10.2d", -10));
	TEST(status, should_test(flags, status), ("%-10.5d", 5000));
	TEST(status, should_test(flags, status), ("%-10.5d", -5000));
	TEST(status, should_test(flags, status), ("%-10.15d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-10.5d", 2147483647));
	TEST(status, should_test(flags, status), ("%-15.d", 0));
	TEST(status, should_test(flags, status), ("%-15.10d", 1));
	TEST(status, should_test(flags, status), ("%-15.5d", 10));
	TEST(status, should_test(flags, status), ("%-15.2d", -10));
	TEST(status, should_test(flags, status), ("%-15.5d", 5000));
	TEST(status, should_test(flags, status), ("%-15.5d", -5000));
	TEST(status, should_test(flags, status), ("%-15.15d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-15.5d", 2147483647));
	TEST(status, should_test(flags, status), ("%-4.5d%d%4d%-10d-d5%-.3d", 3, 4, 5, 6, 7));
	TEST(status, should_test(flags, status), ("%-4.5d%d%4d%-10d-d5%-.3d", 300000, 400000, 500000, 600000, 700000));
	TEST(status, should_test(flags, status), ("%-4.5d%d%4d%-10d-d5%-.3d", -300000, -400000, -500000, -600000, -700000));
	TEST(status, should_test(flags, status), ("%-4.5d%d%4d%-10d-d5%-.3d", 2147483647, 2141483647, 2141483647, 2141483647, 2141483647));
	TEST(status, should_test(flags, status), ("%-4.5d%d%4d%-10d-d5%-.3d", (int)-2147483648, (int)-2141483648, (int)-2141483648, (int)-2141483648, (int)-2141483648));

	flags->should_test = flags->i;
	if (flags->should_test)
		describe("\n%i, widths, precisions and -");

	TEST(status, should_test(flags, status), ("%-i", 0));
	TEST(status, should_test(flags, status), ("%-i", 1));
	TEST(status, should_test(flags, status), ("%-i", 10));
	TEST(status, should_test(flags, status), ("%-i", -10));
	TEST(status, should_test(flags, status), ("%-i", 5000));
	TEST(status, should_test(flags, status), ("%-i", -5000));
	TEST(status, should_test(flags, status), ("%-i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-i", 2147483647));
	TEST(status, should_test(flags, status), ("%-1i", 0));
	TEST(status, should_test(flags, status), ("%-1i", 1));
	TEST(status, should_test(flags, status), ("%-1i", 10));
	TEST(status, should_test(flags, status), ("%-1i", -10));
	TEST(status, should_test(flags, status), ("%-1i", 5000));
	TEST(status, should_test(flags, status), ("%-1i", -5000));
	TEST(status, should_test(flags, status), ("%-1i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-1i", 2147483647));
	TEST(status, should_test(flags, status), ("%-10i", 0));
	TEST(status, should_test(flags, status), ("%-10i", 1));
	TEST(status, should_test(flags, status), ("%-10i", 10));
	TEST(status, should_test(flags, status), ("%-10i", -10));
	TEST(status, should_test(flags, status), ("%-10i", 5000));
	TEST(status, should_test(flags, status), ("%-10i", -5000));
	TEST(status, should_test(flags, status), ("%-10i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-10i", 2147483647));
	TEST(status, should_test(flags, status), ("%-.i", 0));
	TEST(status, should_test(flags, status), ("%-.1i", 1));
	TEST(status, should_test(flags, status), ("%-.2i", 10));
	TEST(status, should_test(flags, status), ("%-.3i", -10));
	TEST(status, should_test(flags, status), ("%-.4i", 5000));
	TEST(status, should_test(flags, status), ("%-.5i", -5000));
	TEST(status, should_test(flags, status), ("%-.6i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-.7i", 2147483647));
	TEST(status, should_test(flags, status), ("%-1.8i", 0));
	TEST(status, should_test(flags, status), ("%-1.9i", 1));
	TEST(status, should_test(flags, status), ("%-1.10i", 10));
	TEST(status, should_test(flags, status), ("%-1.0i", -10));
	TEST(status, should_test(flags, status), ("%-1.6i", 5000));
	TEST(status, should_test(flags, status), ("%-1.4i", -5000));
	TEST(status, should_test(flags, status), ("%-1.10i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-1.12i", 2147483647));
	TEST(status, should_test(flags, status), ("%-10.i", 0));
	TEST(status, should_test(flags, status), ("%-10.10i", 1));
	TEST(status, should_test(flags, status), ("%-10.5i", 10));
	TEST(status, should_test(flags, status), ("%-10.2i", -10));
	TEST(status, should_test(flags, status), ("%-10.5i", 5000));
	TEST(status, should_test(flags, status), ("%-10.5i", -5000));
	TEST(status, should_test(flags, status), ("%-10.15i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-10.5i", 2147483647));
	TEST(status, should_test(flags, status), ("%-15.i", 0));
	TEST(status, should_test(flags, status), ("%-15.10i", 1));
	TEST(status, should_test(flags, status), ("%-15.5i", 10));
	TEST(status, should_test(flags, status), ("%-15.2i", -10));
	TEST(status, should_test(flags, status), ("%-15.5i", 5000));
	TEST(status, should_test(flags, status), ("%-15.5i", -5000));
	TEST(status, should_test(flags, status), ("%-15.15i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%-15.5i", 2147483647));
	TEST(status, should_test(flags, status), ("%-4.5i%i%4i%-10i-i5%-.3i", 3, 4, 5, 6, 7));
	TEST(status, should_test(flags, status), ("%-4.5i%i%4i%-10i-i5%-.3i", 300000, 400000, 500000, 600000, 700000));
	TEST(status, should_test(flags, status), ("%-4.5i%i%4i%-10i-i5%-.3i", -300000, -400000, -500000, -600000, -700000));
	TEST(status, should_test(flags, status), ("%-4.5i%i%4i%-10i-i5%-.3i", 2147483647, 2141483647, 2141483647, 2141483647, 2141483647));
	TEST(status, should_test(flags, status), ("%-4.5i%i%4i%-10i-i5%-.3i", (int)-2147483648, (int)-2141483648, (int)-2141483648, (int)-2141483648, (int)-2141483648));

	flags->should_test = flags->u;
	if (flags->should_test)
		describe("\n%u, widths, precisions and -");

	TEST(status, should_test(flags, status), ("%-u", 0));
	TEST(status, should_test(flags, status), ("%-u", 1));
	TEST(status, should_test(flags, status), ("%-u", 10));
	TEST(status, should_test(flags, status), ("%-u", -10));
	TEST(status, should_test(flags, status), ("%-u", 5000));
	TEST(status, should_test(flags, status), ("%-u", -5000));
	TEST(status, should_test(flags, status), ("%-u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%-u", 2147483647));
	TEST(status, should_test(flags, status), ("%-1u", 0));
	TEST(status, should_test(flags, status), ("%-1u", 1));
	TEST(status, should_test(flags, status), ("%-1u", 10));
	TEST(status, should_test(flags, status), ("%-1u", -10));
	TEST(status, should_test(flags, status), ("%-1u", 5000));
	TEST(status, should_test(flags, status), ("%-1u", -5000));
	TEST(status, should_test(flags, status), ("%-1u", (unsigned int)-1));
	TEST(status, should_test(flags, status), ("%-1u", 2147483647));
	TEST(status, should_test(flags, status), ("%-10u", 0));
	TEST(status, should_test(flags, status), ("%-10u", 1));
	TEST(status, should_test(flags, status), ("%-10u", 10));
	TEST(status, should_test(flags, status), ("%-10u", -10));
	TEST(status, should_test(flags, status), ("%-10u", 5000));
	TEST(status, should_test(flags, status), ("%-10u", -5000));
	TEST(status, should_test(flags, status), ("%-10u", -1));
	TEST(status, should_test(flags, status), ("%-10u", 2147483647));
	TEST(status, should_test(flags, status), ("%-.u", 0));
	TEST(status, should_test(flags, status), ("%-.1u", 1));
	TEST(status, should_test(flags, status), ("%-.2u", 10));
	TEST(status, should_test(flags, status), ("%-.3u", -10));
	TEST(status, should_test(flags, status), ("%-.4u", 5000));
	TEST(status, should_test(flags, status), ("%-.5u", -5000));
	TEST(status, should_test(flags, status), ("%-.6u", -1));
	TEST(status, should_test(flags, status), ("%-.7u", 2147483647));
	TEST(status, should_test(flags, status), ("%-1.8u", 0));
	TEST(status, should_test(flags, status), ("%-1.9u", 1));
	TEST(status, should_test(flags, status), ("%-1.10u", 10));
	TEST(status, should_test(flags, status), ("%-1.0u", -10));
	TEST(status, should_test(flags, status), ("%-1.6u", 5000));
	TEST(status, should_test(flags, status), ("%-1.4u", -5000));
	TEST(status, should_test(flags, status), ("%-1.10u", -1));
	TEST(status, should_test(flags, status), ("%-1.12u", 2147483647));
	TEST(status, should_test(flags, status), ("%-10.u", 0));
	TEST(status, should_test(flags, status), ("%-10.10u", 1));
	TEST(status, should_test(flags, status), ("%-10.5u", 10));
	TEST(status, should_test(flags, status), ("%-10.2u", -10));
	TEST(status, should_test(flags, status), ("%-10.5u", 5000));
	TEST(status, should_test(flags, status), ("%-10.5u", -5000));
	TEST(status, should_test(flags, status), ("%-10.15u", -1));
	TEST(status, should_test(flags, status), ("%-10.5u", 2147483647));
	TEST(status, should_test(flags, status), ("%-15.u", 0));
	TEST(status, should_test(flags, status), ("%-15.10u", 1));
	TEST(status, should_test(flags, status), ("%-15.5u", 10));
	TEST(status, should_test(flags, status), ("%-15.2u", -10));
	TEST(status, should_test(flags, status), ("%-15.5u", 5000));
	TEST(status, should_test(flags, status), ("%-15.5u", -5000));
	TEST(status, should_test(flags, status), ("%-15.15u", -1));
	TEST(status, should_test(flags, status), ("%-15.5u", 2147483647));
	TEST(status, should_test(flags, status), ("%-4.5u%u%4u%-10u-u5%-.3u", 3, 4, 5, 6, 7));
	TEST(status, should_test(flags, status), ("%-4.5u%u%4u%-10u-u5%-.3u", 300000, 400000, 500000, 600000, 700000));
	TEST(status, should_test(flags, status), ("%-4.5u%u%4u%-10u-u5%-.3u", -300000, -400000, -500000, -600000, -700000));
	TEST(status, should_test(flags, status), ("%-4.5u%u%4u%-10u-u5%-.3u", 2147483647, 2141483647, 2141483647, 2141483647, 2141483647));
	TEST(status, should_test(flags, status), ("%-4.5u%u%4u%-10u-u5%-.3u", -1, -1, -1, -1, -1));

	flags->should_test = flags->x;
	if (flags->should_test)
		describe("\n%x, widths, precisions and -");

	TEST(status, should_test(flags, status), ("%-x", 0));
	TEST(status, should_test(flags, status), ("%-x", 1));
	TEST(status, should_test(flags, status), ("%-x", 10));
	TEST(status, should_test(flags, status), ("%-x", -10));
	TEST(status, should_test(flags, status), ("%-x", 5000));
	TEST(status, should_test(flags, status), ("%-x", -5000));
	TEST(status, should_test(flags, status), ("%-x", -1));
	TEST(status, should_test(flags, status), ("%-x", 2147483647));
	TEST(status, should_test(flags, status), ("%-1x", 0));
	TEST(status, should_test(flags, status), ("%-1x", 1));
	TEST(status, should_test(flags, status), ("%-1x", 10));
	TEST(status, should_test(flags, status), ("%-1x", -10));
	TEST(status, should_test(flags, status), ("%-1x", 5000));
	TEST(status, should_test(flags, status), ("%-1x", -5000));
	TEST(status, should_test(flags, status), ("%-1x", -1));
	TEST(status, should_test(flags, status), ("%-1x", 2147483647));
	TEST(status, should_test(flags, status), ("%-10x", 0));
	TEST(status, should_test(flags, status), ("%-10x", 1));
	TEST(status, should_test(flags, status), ("%-10x", 10));
	TEST(status, should_test(flags, status), ("%-10x", -10));
	TEST(status, should_test(flags, status), ("%-10x", 5000));
	TEST(status, should_test(flags, status), ("%-10x", -5000));
	TEST(status, should_test(flags, status), ("%-10x", -1));
	TEST(status, should_test(flags, status), ("%-10x", 2147483647));
	TEST(status, should_test(flags, status), ("%-.x", 0));
	TEST(status, should_test(flags, status), ("%-.1x", 1));
	TEST(status, should_test(flags, status), ("%-.2x", 10));
	TEST(status, should_test(flags, status), ("%-.3x", -10));
	TEST(status, should_test(flags, status), ("%-.4x", 5000));
	TEST(status, should_test(flags, status), ("%-.5x", -5000));
	TEST(status, should_test(flags, status), ("%-.6x", -1));
	TEST(status, should_test(flags, status), ("%-.7x", 2147483647));
	TEST(status, should_test(flags, status), ("%-1.8x", 0));
	TEST(status, should_test(flags, status), ("%-1.9x", 1));
	TEST(status, should_test(flags, status), ("%-1.10x", 10));
	TEST(status, should_test(flags, status), ("%-1.0x", -10));
	TEST(status, should_test(flags, status), ("%-1.6x", 5000));
	TEST(status, should_test(flags, status), ("%-1.4x", -5000));
	TEST(status, should_test(flags, status), ("%-1.10x", -1));
	TEST(status, should_test(flags, status), ("%-1.12x", 2147483647));
	TEST(status, should_test(flags, status), ("%-10.x", 0));
	TEST(status, should_test(flags, status), ("%-10.10x", 1));
	TEST(status, should_test(flags, status), ("%-10.5x", 10));
	TEST(status, should_test(flags, status), ("%-10.2x", -10));
	TEST(status, should_test(flags, status), ("%-10.5x", 5000));
	TEST(status, should_test(flags, status), ("%-10.5x", -5000));
	TEST(status, should_test(flags, status), ("%-10.15x", -1));
	TEST(status, should_test(flags, status), ("%-10.5x", 2147483647));
	TEST(status, should_test(flags, status), ("%-15.x", 0));
	TEST(status, should_test(flags, status), ("%-15.10x", 1));
	TEST(status, should_test(flags, status), ("%-15.5x", 10));
	TEST(status, should_test(flags, status), ("%-15.2x", -10));
	TEST(status, should_test(flags, status), ("%-15.5x", 5000));
	TEST(status, should_test(flags, status), ("%-15.5x", -5000));
	TEST(status, should_test(flags, status), ("%-15.15x", -1));
	TEST(status, should_test(flags, status), ("%-15.5x", 2147483647));
	TEST(status, should_test(flags, status), ("%-4.5x%x%4x%-10x-x5%-.3x", 3, 4, 5, 6, 7));
	TEST(status, should_test(flags, status), ("%-4.5x%x%4x%-10x-x5%-.3x", 300000, 400000, 500000, 600000, 700000));
	TEST(status, should_test(flags, status), ("%-4.5x%x%4x%-10x-x5%-.3x", -300000, -400000, -500000, -600000, -700000));
	TEST(status, should_test(flags, status), ("%-4.5x%x%4x%-10x-x5%-.3x", 2147483647, 2141483647, 2141483647, 2141483647, 2141483647));
	TEST(status, should_test(flags, status), ("%-4.5x%x%4x%-10x-x5%-.3x", -1, -1, -1, -1, -1));

	flags->should_test = flags->X;
	if (flags->should_test)
		describe("\n%X, widths, precisions and -");

	TEST(status, should_test(flags, status), ("%-X", 0));
	TEST(status, should_test(flags, status), ("%-X", 1));
	TEST(status, should_test(flags, status), ("%-X", 10));
	TEST(status, should_test(flags, status), ("%-X", -10));
	TEST(status, should_test(flags, status), ("%-X", 5000));
	TEST(status, should_test(flags, status), ("%-X", -5000));
	TEST(status, should_test(flags, status), ("%-X", -1));
	TEST(status, should_test(flags, status), ("%-X", 2147483647));
	TEST(status, should_test(flags, status), ("%-1X", 0));
	TEST(status, should_test(flags, status), ("%-1X", 1));
	TEST(status, should_test(flags, status), ("%-1X", 10));
	TEST(status, should_test(flags, status), ("%-1X", -10));
	TEST(status, should_test(flags, status), ("%-1X", 5000));
	TEST(status, should_test(flags, status), ("%-1X", -5000));
	TEST(status, should_test(flags, status), ("%-1X", -1));
	TEST(status, should_test(flags, status), ("%-1X", 2147483647));
	TEST(status, should_test(flags, status), ("%-10X", 0));
	TEST(status, should_test(flags, status), ("%-10X", 1));
	TEST(status, should_test(flags, status), ("%-10X", 10));
	TEST(status, should_test(flags, status), ("%-10X", -10));
	TEST(status, should_test(flags, status), ("%-10X", 5000));
	TEST(status, should_test(flags, status), ("%-10X", -5000));
	TEST(status, should_test(flags, status), ("%-10X", -1));
	TEST(status, should_test(flags, status), ("%-10X", 2147483647));
	TEST(status, should_test(flags, status), ("%-.X", 0));
	TEST(status, should_test(flags, status), ("%-.1X", 1));
	TEST(status, should_test(flags, status), ("%-.2X", 10));
	TEST(status, should_test(flags, status), ("%-.3X", -10));
	TEST(status, should_test(flags, status), ("%-.4X", 5000));
	TEST(status, should_test(flags, status), ("%-.5X", -5000));
	TEST(status, should_test(flags, status), ("%-.6X", -1));
	TEST(status, should_test(flags, status), ("%-.7X", 2147483647));
	TEST(status, should_test(flags, status), ("%-1.8X", 0));
	TEST(status, should_test(flags, status), ("%-1.9X", 1));
	TEST(status, should_test(flags, status), ("%-1.10X", 10));
	TEST(status, should_test(flags, status), ("%-1.0X", -10));
	TEST(status, should_test(flags, status), ("%-1.6X", 5000));
	TEST(status, should_test(flags, status), ("%-1.4X", -5000));
	TEST(status, should_test(flags, status), ("%-1.10X", -1));
	TEST(status, should_test(flags, status), ("%-1.12X", 2147483647));
	TEST(status, should_test(flags, status), ("%-10.X", 0));
	TEST(status, should_test(flags, status), ("%-10.10X", 1));
	TEST(status, should_test(flags, status), ("%-10.5X", 10));
	TEST(status, should_test(flags, status), ("%-10.2X", -10));
	TEST(status, should_test(flags, status), ("%-10.5X", 5000));
	TEST(status, should_test(flags, status), ("%-10.5X", -5000));
	TEST(status, should_test(flags, status), ("%-10.15X", -1));
	TEST(status, should_test(flags, status), ("%-10.5X", 2147483647));
	TEST(status, should_test(flags, status), ("%-15.X", 0));
	TEST(status, should_test(flags, status), ("%-15.10X", 1));
	TEST(status, should_test(flags, status), ("%-15.5X", 10));
	TEST(status, should_test(flags, status), ("%-15.2X", -10));
	TEST(status, should_test(flags, status), ("%-15.5X", 5000));
	TEST(status, should_test(flags, status), ("%-15.5X", -5000));
	TEST(status, should_test(flags, status), ("%-15.15X", -1));
	TEST(status, should_test(flags, status), ("%-15.5X", 2147483647));
	TEST(status, should_test(flags, status), ("%-4.5X%X%4X%-10X-X5%-.3X", 3, 4, 5, 6, 7));
	TEST(status, should_test(flags, status), ("%-4.5X%X%4X%-10X-X5%-.3X", 300000, 400000, 500000, 600000, 700000));
	TEST(status, should_test(flags, status), ("%-4.5X%X%4X%-10X-X5%-.3X", -300000, -400000, -500000, -600000, -700000));
	TEST(status, should_test(flags, status), ("%-4.5X%X%4X%-10X-X5%-.3X", 2147483647, 2141483647, 2141483647, 2141483647, 2141483647));
	TEST(status, should_test(flags, status), ("%-4.5X%X%4X%-10X-X5%-.3X", -1, -1, -1, -1, -1));

	flags->should_test = flags->d;
	if (flags->should_test)
		describe("\n%d, widths, precisions and 0");

	TEST(status, should_test(flags, status), ("%01d", 0));
	TEST(status, should_test(flags, status), ("%01d", -4));
	TEST(status, should_test(flags, status), ("%010d", 42));
	TEST(status, should_test(flags, status), ("%042d", 42000));
	TEST(status, should_test(flags, status), ("%020d", -42000));
	TEST(status, should_test(flags, status), ("wait for it... %050d", 42));
	TEST(status, should_test(flags, status), ("%020d is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%05d", 2147483647));
	TEST(status, should_test(flags, status), ("%030d", 2147483647));
	TEST(status, should_test(flags, status), ("%010d", 2147483647));
	TEST(status, should_test(flags, status), ("%05d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%030d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%010d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%011d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%012d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%012d, %20d, %2d, %42d", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%012d, %d, %2d, %42d", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014d%020d%02d%0d", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014dc%020ds%02dx%0du", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%01.d", 0));
	TEST(status, should_test(flags, status), ("%01.0d", 0));
	TEST(status, should_test(flags, status), ("%02.0d", 0));
	TEST(status, should_test(flags, status), ("%03.0d", 0));
	TEST(status, should_test(flags, status), ("%01.1d", 0));
	TEST(status, should_test(flags, status), ("%01.2d", 0));
	TEST(status, should_test(flags, status), ("%01.3d", 0));
	TEST(status, should_test(flags, status), ("%01.0d", -4));
	TEST(status, should_test(flags, status), ("%01.1d", -4));
	TEST(status, should_test(flags, status), ("%01.2d", -4));
	TEST(status, should_test(flags, status), ("%01.3d", -4));
	TEST(status, should_test(flags, status), ("%01.0d", 4));
	TEST(status, should_test(flags, status), ("%01.1d", 4));
	TEST(status, should_test(flags, status), ("%01.2d", 4));
	TEST(status, should_test(flags, status), ("%01.3d", 4));
	TEST(status, should_test(flags, status), ("%010.20d", 42));
	TEST(status, should_test(flags, status), ("%042.2d", 42000));
	TEST(status, should_test(flags, status), ("%042.20d", 42000));
	TEST(status, should_test(flags, status), ("%042.42d", 42000));
	TEST(status, should_test(flags, status), ("%042.52d", 42000));
	TEST(status, should_test(flags, status), ("%020.10d", -42000));
	TEST(status, should_test(flags, status), ("%020.20d", -42000));
	TEST(status, should_test(flags, status), ("%020.30d", -42000));
	TEST(status, should_test(flags, status), ("wait for it... %050.50d", 42));
	TEST(status, should_test(flags, status), ("%020.19d is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%020.20d is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%020.21d is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%05d", 2147483647));
	TEST(status, should_test(flags, status), ("%030d", 2147483647));
	TEST(status, should_test(flags, status), ("%09d", 2147483647));
	TEST(status, should_test(flags, status), ("%010d", 2147483647));
	TEST(status, should_test(flags, status), ("%011d", 2147483647));
	TEST(status, should_test(flags, status), ("%05d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%030d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%010d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%011d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%012d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%012d, %20d, %2d, %000042d", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%012d, %d, %002d, %42d", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%0014.2d%020d%0002.d%000.5d", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014dc%020ds%02dx%0du", (int)-2147483648, 3, 30, -1));

	flags->should_test = flags->i;
	if (flags->should_test)
		describe("\n%i, widths, precisions and 0");

	TEST(status, should_test(flags, status), ("%01i", 0));
	TEST(status, should_test(flags, status), ("%01i", -4));
	TEST(status, should_test(flags, status), ("%010i", 42));
	TEST(status, should_test(flags, status), ("%042i", 42000));
	TEST(status, should_test(flags, status), ("%020i", -42000));
	TEST(status, should_test(flags, status), ("wait for it... %050i", 42));
	TEST(status, should_test(flags, status), ("%020i is how many tests are going to be maie", 8000));
	TEST(status, should_test(flags, status), ("%05i", 2147483647));
	TEST(status, should_test(flags, status), ("%030i", 2147483647));
	TEST(status, should_test(flags, status), ("%010i", 2147483647));
	TEST(status, should_test(flags, status), ("%05i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%030i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%010i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%011i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%012i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%012i, %20i, %2i, %42i", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%012i, %i, %2i, %42i", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014i%020i%02i%0i", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014ic%020is%02ix%0iu", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%01.i", 0));
	TEST(status, should_test(flags, status), ("%01.0i", 0));
	TEST(status, should_test(flags, status), ("%02.0i", 0));
	TEST(status, should_test(flags, status), ("%03.0i", 0));
	TEST(status, should_test(flags, status), ("%01.1i", 0));
	TEST(status, should_test(flags, status), ("%01.2i", 0));
	TEST(status, should_test(flags, status), ("%01.3i", 0));
	TEST(status, should_test(flags, status), ("%01.0i", -4));
	TEST(status, should_test(flags, status), ("%01.1i", -4));
	TEST(status, should_test(flags, status), ("%01.2i", -4));
	TEST(status, should_test(flags, status), ("%01.3i", -4));
	TEST(status, should_test(flags, status), ("%01.0i", 4));
	TEST(status, should_test(flags, status), ("%01.1i", 4));
	TEST(status, should_test(flags, status), ("%01.2i", 4));
	TEST(status, should_test(flags, status), ("%01.3i", 4));
	TEST(status, should_test(flags, status), ("%010.20i", 42));
	TEST(status, should_test(flags, status), ("%042.2i", 42000));
	TEST(status, should_test(flags, status), ("%042.20i", 42000));
	TEST(status, should_test(flags, status), ("%042.42i", 42000));
	TEST(status, should_test(flags, status), ("%042.52i", 42000));
	TEST(status, should_test(flags, status), ("%020.10i", -42000));
	TEST(status, should_test(flags, status), ("%020.20i", -42000));
	TEST(status, should_test(flags, status), ("%020.30i", -42000));
	TEST(status, should_test(flags, status), ("wait for it... %050.50i", 42));
	TEST(status, should_test(flags, status), ("%020.19i is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%020.20i is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%020.21i is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%05i", 2147483647));
	TEST(status, should_test(flags, status), ("%030i", 2147483647));
	TEST(status, should_test(flags, status), ("%09i", 2147483647));
	TEST(status, should_test(flags, status), ("%010i", 2147483647));
	TEST(status, should_test(flags, status), ("%011i", 2147483647));
	TEST(status, should_test(flags, status), ("%05i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%030i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%010i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%011i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%012i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%012i, %20i, %2i, %000042i", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%012i, %i, %002i, %42i", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%0014.2i%020i%0002.i%000.5i", (int)-2147483648, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014ic%020is%02ix%0iu", (int)-2147483648, 3, 30, -1));

	flags->should_test = flags->u;
	if (flags->should_test)
		describe("\n%u, widths, precisions and 0");

	TEST(status, should_test(flags, status), ("%01u", 0));
	TEST(status, should_test(flags, status), ("%01u", -4));
	TEST(status, should_test(flags, status), ("%010u", 42));
	TEST(status, should_test(flags, status), ("%042u", 42000));
	TEST(status, should_test(flags, status), ("%020u", -42000));
	TEST(status, should_test(flags, status), ("wait for it... %050u", 42));
	TEST(status, should_test(flags, status), ("%020u is how many tests are going to be maie", 8000));
	TEST(status, should_test(flags, status), ("%05u", 2147483647));
	TEST(status, should_test(flags, status), ("%030u", 2147483647));
	TEST(status, should_test(flags, status), ("%010u", 2147483647));
	TEST(status, should_test(flags, status), ("%05u", -1));
	TEST(status, should_test(flags, status), ("%030u", -1));
	TEST(status, should_test(flags, status), ("%010u", -1));
	TEST(status, should_test(flags, status), ("%011u", -1));
	TEST(status, should_test(flags, status), ("%012u", -1));
	TEST(status, should_test(flags, status), ("%012u, %20u, %2u, %42u", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%012u, %u, %2u, %42u", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014u%020u%02u%0u", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014uc%020us%02ux%0ui", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%01.u", 0));
	TEST(status, should_test(flags, status), ("%01.0u", 0));
	TEST(status, should_test(flags, status), ("%02.0u", 0));
	TEST(status, should_test(flags, status), ("%03.0u", 0));
	TEST(status, should_test(flags, status), ("%01.1u", 0));
	TEST(status, should_test(flags, status), ("%01.2u", 0));
	TEST(status, should_test(flags, status), ("%01.3u", 0));
	TEST(status, should_test(flags, status), ("%01.0u", 4));
	TEST(status, should_test(flags, status), ("%01.1u", 4));
	TEST(status, should_test(flags, status), ("%01.2u", 4));
	TEST(status, should_test(flags, status), ("%01.3u", 4));
	TEST(status, should_test(flags, status), ("%010.20u", 42));
	TEST(status, should_test(flags, status), ("%042.2u", 42000));
	TEST(status, should_test(flags, status), ("%042.20u", 42000));
	TEST(status, should_test(flags, status), ("%042.42u", 42000));
	TEST(status, should_test(flags, status), ("%042.52u", 42000));
	TEST(status, should_test(flags, status), ("wait for it... %050.50u", 42));
	TEST(status, should_test(flags, status), ("%020.19u is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%020.20u is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%020.21u is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%05u", 2147483647));
	TEST(status, should_test(flags, status), ("%030u", 2147483647));
	TEST(status, should_test(flags, status), ("%09u", 2147483647));
	TEST(status, should_test(flags, status), ("%010u", 2147483647));
	TEST(status, should_test(flags, status), ("%011u", 2147483647));
	TEST(status, should_test(flags, status), ("%05u",  -1));
	TEST(status, should_test(flags, status), ("%030u", -1));
	TEST(status, should_test(flags, status), ("%010u", -1));
	TEST(status, should_test(flags, status), ("%011u", -1));
	TEST(status, should_test(flags, status), ("%012u", -1));
	TEST(status, should_test(flags, status), ("%012u, %20u, %2u, %000042u", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%012u, %u, %002u, %42u", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%0014.2u%020u%0002.u%000.5u", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014uc%020us%02ux%0ui", -1, 3, 30, -1));

	flags->should_test = flags->x;
	if (flags->should_test)
		describe("\n%x, widths, precisions and 0");

	TEST(status, should_test(flags, status), ("%01x", 0));
	TEST(status, should_test(flags, status), ("%01x", -4));
	TEST(status, should_test(flags, status), ("%010x", 42));
	TEST(status, should_test(flags, status), ("%042x", 42000));
	TEST(status, should_test(flags, status), ("%020x", -42000));
	TEST(status, should_test(flags, status), ("wait for it... %050x", 42));
	TEST(status, should_test(flags, status), ("%020x is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%05x", 2147483647));
	TEST(status, should_test(flags, status), ("%030x", 2147483647));
	TEST(status, should_test(flags, status), ("%010x", 2147483647));
	TEST(status, should_test(flags, status), ("%05x", -1));
	TEST(status, should_test(flags, status), ("%030x", -1));
	TEST(status, should_test(flags, status), ("%010x", -1));
	TEST(status, should_test(flags, status), ("%011x", -1));
	TEST(status, should_test(flags, status), ("%012x", -1));
	TEST(status, should_test(flags, status), ("%012x, %20x, %2x, %42x", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%012x, %x, %2x, %42x", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014x%020x%02x%0x", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014xc%020xs%02xX%0xi", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%01.x", 0));
	TEST(status, should_test(flags, status), ("%01.0x", 0));
	TEST(status, should_test(flags, status), ("%02.0x", 0));
	TEST(status, should_test(flags, status), ("%03.0x", 0));
	TEST(status, should_test(flags, status), ("%01.1x", 0));
	TEST(status, should_test(flags, status), ("%01.2x", 0));
	TEST(status, should_test(flags, status), ("%01.3x", 0));
	TEST(status, should_test(flags, status), ("%01.0x", 4));
	TEST(status, should_test(flags, status), ("%01.1x", 4));
	TEST(status, should_test(flags, status), ("%01.2x", 4));
	TEST(status, should_test(flags, status), ("%01.3x", 4));
	TEST(status, should_test(flags, status), ("%010.20x", 42));
	TEST(status, should_test(flags, status), ("%042.2x", 42000));
	TEST(status, should_test(flags, status), ("%042.20x", 42000));
	TEST(status, should_test(flags, status), ("%042.42x", 42000));
	TEST(status, should_test(flags, status), ("%042.52x", 42000));
	TEST(status, should_test(flags, status), ("wait for it... %050.50x", 42));
	TEST(status, should_test(flags, status), ("%020.19x is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%020.20x is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%020.21x is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%05x", 2147483647));
	TEST(status, should_test(flags, status), ("%030x", 2147483647));
	TEST(status, should_test(flags, status), ("%09x", 2147483647));
	TEST(status, should_test(flags, status), ("%010x", 2147483647));
	TEST(status, should_test(flags, status), ("%011x", 2147483647));
	TEST(status, should_test(flags, status), ("%05x",  -1));
	TEST(status, should_test(flags, status), ("%030x", -1));
	TEST(status, should_test(flags, status), ("%010x", -1));
	TEST(status, should_test(flags, status), ("%011x", -1));
	TEST(status, should_test(flags, status), ("%012x", -1));
	TEST(status, should_test(flags, status), ("%012x, %20x, %2x, %000042x", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%012x, %x, %002x, %42x", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%0014.2x%020x%0002.x%000.5x", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014xc%020xs%02xx%0xi", -1, 3, 30, -1));

	flags->should_test = flags->X;
	if (flags->should_test)
		describe("\n%X, widths, precisions and 0");

	TEST(status, should_test(flags, status), ("%01X", 0));
	TEST(status, should_test(flags, status), ("%01X", -4));
	TEST(status, should_test(flags, status), ("%010X", 42));
	TEST(status, should_test(flags, status), ("%042X", 42000));
	TEST(status, should_test(flags, status), ("%020X", -42000));
	TEST(status, should_test(flags, status), ("wait for it... %050X", 42));
	TEST(status, should_test(flags, status), ("%020X is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%05X", 2147483647));
	TEST(status, should_test(flags, status), ("%030X", 2147483647));
	TEST(status, should_test(flags, status), ("%010X", 2147483647));
	TEST(status, should_test(flags, status), ("%05X", -1));
	TEST(status, should_test(flags, status), ("%030X", -1));
	TEST(status, should_test(flags, status), ("%010X", -1));
	TEST(status, should_test(flags, status), ("%011X", -1));
	TEST(status, should_test(flags, status), ("%012X", -1));
	TEST(status, should_test(flags, status), ("%012X, %20X, %2X, %42X", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%012X, %X, %2X, %42X", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014X%020X%02X%0X", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014Xc%020Xs%02XX%0Xi", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%01.X", 0));
	TEST(status, should_test(flags, status), ("%01.0X", 0));
	TEST(status, should_test(flags, status), ("%02.0X", 0));
	TEST(status, should_test(flags, status), ("%03.0X", 0));
	TEST(status, should_test(flags, status), ("%01.1X", 0));
	TEST(status, should_test(flags, status), ("%01.2X", 0));
	TEST(status, should_test(flags, status), ("%01.3X", 0));
	TEST(status, should_test(flags, status), ("%01.0X", 4));
	TEST(status, should_test(flags, status), ("%01.1X", 4));
	TEST(status, should_test(flags, status), ("%01.3X", 4));
	TEST(status, should_test(flags, status), ("%010.20X", 42));
	TEST(status, should_test(flags, status), ("%042.2X", 42000));
	TEST(status, should_test(flags, status), ("%042.20X", 42000));
	TEST(status, should_test(flags, status), ("%042.42X", 42000));
	TEST(status, should_test(flags, status), ("%042.52X", 42000));
	TEST(status, should_test(flags, status), ("wait for it... %050.50X", 42));
	TEST(status, should_test(flags, status), ("%020.19X is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%020.20X is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%020.21X is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%05X", 2147483647));
	TEST(status, should_test(flags, status), ("%030X", 2147483647));
	TEST(status, should_test(flags, status), ("%09X", 2147483647));
	TEST(status, should_test(flags, status), ("%010X", 2147483647));
	TEST(status, should_test(flags, status), ("%011X", 2147483647));
	TEST(status, should_test(flags, status), ("%05X",  -1));
	TEST(status, should_test(flags, status), ("%030.20X", -1));
	TEST(status, should_test(flags, status), ("%010.11X", -1));
	TEST(status, should_test(flags, status), ("%011.11X", -1));
	TEST(status, should_test(flags, status), ("%012.11X", -1));
	TEST(status, should_test(flags, status), ("%012X, %20X, %2X, %000042.20X", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%012X, %X, %002X, %42.5X", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%0014.2X%020X%0002.X%000.5X", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%014Xc%020Xs%02.5XX%0.Xi", -1, 3, 30, -1));

	flags->should_test = flags->x;
	if (flags->should_test)
		describe("\n%x and #");

	TEST(status, should_test(flags, status), ("%#x", 0));
	TEST(status, should_test(flags, status), ("%#x", -4));
	TEST(status, should_test(flags, status), ("%#x", 42));
	TEST(status, should_test(flags, status), ("%#x", 42000));
	TEST(status, should_test(flags, status), ("%#x", -42000));
	TEST(status, should_test(flags, status), ("wait for it... %#x", 42));
	TEST(status, should_test(flags, status), ("%#x is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%#xd", 2147483647));
	TEST(status, should_test(flags, status), ("%#xp", 2147483647));
	TEST(status, should_test(flags, status), ("%#xX", 2147483647));
	TEST(status, should_test(flags, status), ("%#xp", -1));
	TEST(status, should_test(flags, status), ("%#xd", -1));
	TEST(status, should_test(flags, status), ("%#xX", -1));
	TEST(status, should_test(flags, status), ("%#x", -1));
	TEST(status, should_test(flags, status), ("%#x, %x, %x, %x", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%#x%#x%#x%#x", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%#xc%#xs%#xX%#xi", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("--.%#xp", 0));
	TEST(status, should_test(flags, status), ("--.%#xs", 0));
	TEST(status, should_test(flags, status), ("%#xc", 4));
	TEST(status, should_test(flags, status), ("c%#x-i", 42000));
	TEST(status, should_test(flags, status), ("wait for it... %#xp", 42));

	flags->should_test = flags->X;
	if (flags->should_test)
		describe("\n%X and #");

	TEST(status, should_test(flags, status), ("%#X", 0));
	TEST(status, should_test(flags, status), ("%#X", -4));
	TEST(status, should_test(flags, status), ("%#X", 42));
	TEST(status, should_test(flags, status), ("%#X", 42000));
	TEST(status, should_test(flags, status), ("%#X", -42000));
	TEST(status, should_test(flags, status), ("wait for it... %#X", 42));
	TEST(status, should_test(flags, status), ("%#X is how many tests are going to be made", 8000));
	TEST(status, should_test(flags, status), ("%#Xd", 2147483647));
	TEST(status, should_test(flags, status), ("%#Xp", 2147483647));
	TEST(status, should_test(flags, status), ("%#XX", 2147483647));
	TEST(status, should_test(flags, status), ("%#Xp", -1));
	TEST(status, should_test(flags, status), ("%#Xd", -1));
	TEST(status, should_test(flags, status), ("%#XX", -1));
	TEST(status, should_test(flags, status), ("%#X", -1));
	TEST(status, should_test(flags, status), ("%#X, %X, %X, %X", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%#X%#X%#X%#X", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("%#Xc%#Xs%#Xx%#Xi", -1, 3, 30, -1));
	TEST(status, should_test(flags, status), ("--.%#Xp", 0));
	TEST(status, should_test(flags, status), ("--.%#Xs", 0));
	TEST(status, should_test(flags, status), ("%#Xc", 4));
	TEST(status, should_test(flags, status), ("c%#X-i", 42000));
	TEST(status, should_test(flags, status), ("wait for it... %#Xp", 42));

	flags->should_test = flags->d;
	if (flags->should_test)
		describe("\n%d and ' '");

	TEST(status, should_test(flags, status), ("% d", 0));
	TEST(status, should_test(flags, status), ("% d", 1));
	TEST(status, should_test(flags, status), ("% d", -1));
	TEST(status, should_test(flags, status), ("%    d", 0));
	TEST(status, should_test(flags, status), ("%   d", 1));
	TEST(status, should_test(flags, status), ("%  d", -1));
	TEST(status, should_test(flags, status), ("% d", 2147483647));
	TEST(status, should_test(flags, status), ("% d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%   d", 2147483647));
	TEST(status, should_test(flags, status), ("%  d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("% d", 2178647));
	TEST(status, should_test(flags, status), ("% d", (int)-2144348));
	TEST(status, should_test(flags, status), ("%   d", 2147837));
	TEST(status, should_test(flags, status), ("%  d", (int)-2147486));
	TEST(status, should_test(flags, status), ("%  d this is %d getting% di hard :/", (int)-2147486, -2, 42));

	flags->should_test = flags->i;
	if (flags->should_test)
		describe("\n%i and ' '");

	TEST(status, should_test(flags, status), ("% i", 0));
	TEST(status, should_test(flags, status), ("% i", 2));
	TEST(status, should_test(flags, status), ("% i", -2));
	TEST(status, should_test(flags, status), ("%    i", 0));
	TEST(status, should_test(flags, status), ("%   i", 1));
	TEST(status, should_test(flags, status), ("%  i", -1));
	TEST(status, should_test(flags, status), ("% i", 2147483647));
	TEST(status, should_test(flags, status), ("% i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%   i", 2147483647));
	TEST(status, should_test(flags, status), ("%  i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("% i", 2178647));
	TEST(status, should_test(flags, status), ("% i", (int)-2144348));
	TEST(status, should_test(flags, status), ("%   i", 2147837));
	TEST(status, should_test(flags, status), ("%  i", (int)-2147486));
	TEST(status, should_test(flags, status), ("%  i this is %i getting% is hari :/", (int)-2147486, -2, 42));

	flags->should_test = flags->d;
	if (flags->should_test)
		describe("\n%d and +");

	TEST(status, should_test(flags, status), ("%+d", 0));
	TEST(status, should_test(flags, status), ("%+d", 1));
	TEST(status, should_test(flags, status), ("%+d", -1));
	TEST(status, should_test(flags, status), ("%+d", 24));
	TEST(status, should_test(flags, status), ("%+d", 42));
	TEST(status, should_test(flags, status), ("%+d", -42));
	TEST(status, should_test(flags, status), ("%+d", 2147483647));
	TEST(status, should_test(flags, status), ("%+d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%+++d", 2147483647));
	TEST(status, should_test(flags, status), ("%++d", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%+d", 2178647));
	TEST(status, should_test(flags, status), ("%+d", (int)-2144348));
	TEST(status, should_test(flags, status), ("%+++d", 2147837));
	TEST(status, should_test(flags, status), ("%++d", (int)-2147486));
	TEST(status, should_test(flags, status), ("%++d this is %d getting%+di hard :/", (int)-2147486, -2, 42));

	flags->should_test = flags->d;
	if (flags->should_test)
		describe("\n%d and +");

	TEST(status, should_test(flags, status), ("%+i", 0));
	TEST(status, should_test(flags, status), ("%+i", 1));
	TEST(status, should_test(flags, status), ("%+i", -1));
	TEST(status, should_test(flags, status), ("%+i", 24));
	TEST(status, should_test(flags, status), ("%+i", 42));
	TEST(status, should_test(flags, status), ("%+i", -42));
	TEST(status, should_test(flags, status), ("%+i", 2147483647));
	TEST(status, should_test(flags, status), ("%+i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%+++i", 2147483647));
	TEST(status, should_test(flags, status), ("%++i", (int)-2147483648));
	TEST(status, should_test(flags, status), ("%+i", 2178647));
	TEST(status, should_test(flags, status), ("%+i", (int)-2144348));
	TEST(status, should_test(flags, status), ("%+++i", 2147837));
	TEST(status, should_test(flags, status), ("%++i", (int)-2147486));
	TEST(status, should_test(flags, status), ("%++i this is %i getting%+ix hard :/", (int)-2147486, -2, 42));	
}