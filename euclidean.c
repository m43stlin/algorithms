#include <stdio.h>
int main() {
	int n1, n2, on1, on2, slctn, lcm;

	/*
	 * Have the user choose to whether display Least Common Multiple
	 * or Greatest Common Divisor
	 */
	printf("Choose which to calculate: 1. LCM, 2. GCD\n");
	scanf("%d", &slctn);

	if (slctn) {
		printf("Enter two positive integers: ");
		scanf("%d %d", &n1, &n2);

		/*
		 * Store original values entered by the user for calculation
		 * of LCM;
		 *
		 * (n1*n2)/gcd
		 */
		on1 = n1;
		on2 = n2;

		/*
		 * Euclidean Algorithm
		 *
		 * The output of each step is used as the input for the next step.
		 * Ex. 81 and 153
		 *
		 * k		Equation		q,  r
		 * --	-----------------	-----
		 * 0	153 = 1 * 81 + 72	1, 72
		 * 1	81	= 1 * 72 +  9	1, 	9
		 * 2	72	= 3 *  9 + 	0	3,  0
		 *
		 * Since a 0 remainder was reached in step two we know that 9 is the gcd.
		 *
		 *
		 * Worked example (subtraction based version).
		 *
		 * n2 > n1
		 *
		 * n2 -= n1
		 * 		153 -= 81 = 72
		 * 		n2 = 72
		 * 	------------------------------------
		 *
		 * n1 > n2
		 *
		 * n1 -= n2
		 * 		81 -= 72 = 9
		 * 		n1 = 9
		 * -------------------------------------
		 *
		 * n2 > n1
		 *
		 * 		72 -= 9
		 * 		n2 = 63 ...
		 *
		 * Subtraction continues until n1 = n2
		 */
		while (n1 != n2) {
			if (n1 > n2)
				n1 -= n2;
			else
				n2 -= n1;

			if (slctn == 2) {
				printf("n1 = %d\n", n1);
				printf("n2 = %d\n", n2);
			}
		}

		if (slctn == 1) {
			lcm = (on1 * on2)/n1;
			printf("LCM = %d", lcm);
		} else {
			printf("GCD = %d", n1);
		}
	}

	return 0;
}