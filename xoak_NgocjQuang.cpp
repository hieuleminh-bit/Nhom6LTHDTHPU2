void M1C::xoak(int k) {
    for (int i = k; i < spt - 1; i++) {
        a[i] = a[i + 1];
    }

    spt--;
}
