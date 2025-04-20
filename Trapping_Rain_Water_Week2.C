int trap(int* height, int heightSize) {
    if (heightSize == 0) return 0;

    int leftMax[heightSize];
    int rightMax[heightSize];
    int water = 0;

    leftMax[0] = height[0];
    for (int i = 1; i < heightSize; i++) {
        leftMax[i] = (height[i] > leftMax[i - 1]) ? height[i] : leftMax[i - 1];
    }

    rightMax[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--) {
        rightMax[i] = (height[i] > rightMax[i + 1]) ? height[i] : rightMax[i + 1];
    }

    for (int i = 0; i < heightSize; i++) {
        int minHeight = (leftMax[i] < rightMax[i]) ? leftMax[i] : rightMax[i];
        if (minHeight > height[i]) {
            water += minHeight - height[i];
        }
    }

    return water;
}
