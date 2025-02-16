#include "test.h"
#include <stdio.h>


int main() {
	unsigned int num1 = 12345;
	unsigned int num2 = 67890;
	unsigned int num3 = 0;
	unsigned int max_uint = UINT_MAX;

	test_printf("|%u|\n", num1);               // Basic unsigned
	test_printf("|%.0u|\n", num1);               // Basic unsigned
	test_printf("|%-u|\n", num1);              // Left-justified with '-'
	test_printf("|%05u|\n", num1);             // Zero-padded with width
	test_printf("|%5u|\n", num1);              // Right-justified with width
	test_printf("|%-5u|\n", num2);             // Left-justified with width
	test_printf("|%.5u|\n", num1);             // Precision greater than number length
	test_printf("|%10.5u|\n", num1);           // Combined width and precision
	test_printf("|%-10.5u|\n", num2);          // Left-justified with width and precision
	test_printf("|%u|\n", num3);               // Zero value
	test_printf("|%.u|\n", num3);              // Precision with zero value (prints nothing)
	test_printf("|%5u|\n", num3);              // Width with zero value
	test_printf("|%-5u|\n", num3);             // Left-justified width with zero value
	test_printf("|%010u|\n", num3);            // Zero-padded width with zero value
	test_printf("|%u|\n", max_uint);           // Maximum unsigned integer value
	test_printf("|%+u|\n", num1);              // '+' flag (undefined for unsigned)
	test_printf("|% u|\n", num1);              // ' ' (space) flag (undefined for unsigned)
	test_printf("|%+10u|\n", num2);            // '+' with width (undefined for unsigned)
	test_printf("|%-+5u|\n", num1);            // '+' and '-' combined (undefined for unsigned)
	test_printf("|% +5u|\n", num1);            // ' ' and '+' combined (undefined for unsigned)
	test_printf("|%0-.5u|\n", num1);           // Precision before '0' flag (undefined)
	test_printf("|%5-.u|\n", num1);            // Width, then flag '-', then precision (undefined)
	test_printf("|%.5-5u|\n", num2);           // Precision with width after '-' (undefined)
	test_printf("|%-0u|\n", num1);             // Conflicting flags '-' and '0' (undefined)
	test_printf("|%+ 0u|\n", num1);            // Conflicting '+' and ' ' with '0' flag (undefined)
	test_printf("|%50u|\n", num1);             // Large width with unsigned
	test_printf("|%.50u|\n", num1);            // Excessive precision
	test_printf("|%100u|\n", num1);            // Very large width
	test_printf("|%-100u|\n", num2);           // Left-justified very large width
	test_printf("|%100.50u|\n", num1);         // Combined large width and excessive precision
	test_printf("|%-100.50u|\n", num2);        // Left-justified large width and excessive precision
	test_printf("|%u%u%u|\n", num1, num2, num3);  // Multiple unsigned arguments
	test_printf("|%10u%-10u%.5u|\n", num1, num2, 42);  // Mixed width, flags, and precision
	test_printf("|%-20.5u%20.5u%10u|\n", num1, num2, num3);  // Alignment and truncation
	test_printf("|%-10u%-10u%-10u%-10u%-10u|\n", num1, num2, num3, max_uint, num1);  // Many unsigneds
	test_printf("|%5u %5u %5u|\n", 1u, 2u, 3u);  // Spaced unsigneds
	test_printf("|%-0-5u|\n", num1);           // Conflicting flags and width (undefined)
	test_printf("|%--0u|\n", num2);            // Multiple conflicting flags (undefined)
	test_printf("|%-.5u|\n", num1);            // Precision before '-' (undefined)
	test_printf("|%.0-5u|\n", num1);           // Precision and width in wrong order (undefined)
	test_printf("|%5-.u|\n", num2);            // Width, then '-' and precision (undefined)
	test_printf("|%+0-5u|\n", num1);           // Conflicting '+' and '0' with '-' (undefined)
	test_printf("|%u|\n", LONG_MAX);
	test_printf("|%u|\n", ULONG_MAX);
	test_printf("|%u|\n", ULONG_MAX);
	test_printf("|%u|\n", 9223372036854775807LL);
	test_printf("|%u|\n", INT_MAX);
	test_printf("|%u|\n", INT_MAX);
	test_printf("|%u|\n", INT_MIN);
	test_printf("|%-12u|\n", LONG_MIN);
	test_printf("|%-13u|\n", UINT_MAX);
	test_printf("|%-15u|\n", 9223372036854775807LL);
	test_printf("|%-9u %-10u %-11u %-12u %-13u %-14u %-15u|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	test_printf("|%01u|\n", 0);

	return 0;
}
