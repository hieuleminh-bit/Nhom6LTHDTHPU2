void M1C::sapxep() {
    for (int i = 0; i < spt - 1; i++) {
        for (int j = i + 1; j < spt; j++) {
            if (a[i] > a[j]) {
                int tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }
}
