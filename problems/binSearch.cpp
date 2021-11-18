int main() {
    std::array<int, 3> a2 = { 1, 2, 3 };
    
    int l = 0, r = a2.size(), mid = 0;
    int toFind = 2;
    std::sort(a2.begin() , a2.end());

    while (l - r != 1)
    {
        mid = (l + r) / 2;
        if (a2[mid] > toFind)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

    }

    std::cout << r;
}
