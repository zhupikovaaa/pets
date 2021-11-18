int main() {
    std::array<int, 3> a2 = { 7, 23, 1 };
    
    for(int i = 0; i < a2.size(); ++i)
        for (int j = i + 1; j < a2.size(); ++j)
        {
            if (a2[i] > a2[j]) std::swap(a2[i], a2[j]);
        }

    for (int i = 0; i < a2.size(); ++i)
        std::cout << a2[i] << " ";;
}
