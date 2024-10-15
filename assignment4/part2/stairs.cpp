int ways_to_top(int n) {
    
    //if there are 0 or less stairs than there are no ways to go the stairs as it doesn't make sense logically
    if(n < 1) return 0;

    //base case for certain number of ways to go up one stair
	else if(n == 1) return 1;

    //base case for certain number of ways to go up two stairs
    else if(n == 2) return 2;

    //base case for certain number of ways to go up three stairs
    else if(n == 3) return 4;

    //calling the function three times simulates one step, two steps, and three steps
    return ways_to_top(n-1) + ways_to_top(n-2) + ways_to_top(n-3);
}
