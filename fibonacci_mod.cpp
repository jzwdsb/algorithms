//
// Created by manout on 17-12-19.
//

#include <iostream>
#include <vector>
#include <cmath>


int main()
{
	int n;
	int *ans;
	std::cin >> n;
	ans = new int [n + 2];
	ans[1] = 1;
	ans[2] = 1;
	for (int i = 3; i < n + 1; ++i)
	{
		ans[i] = (ans[i - 1 ] + ans[i - 2]) % 10007;
	}
	std::cout << ans[n];
	delete ans;
}