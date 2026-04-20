# Laporan Programming Assignment 3: Simple STL

## Identitas

| Atribut | Keterangan |
|---------|------------|
| **Nama** | Dzaky Haady |
| **NRP** | 5024241076 |
| **Mata Kuliah** | Pemrograman Lanjut |
| **Assignment** | Programming Assignment 4 |
| **Topik** | Simple STL - Pendeteksi Tipe Segitiga |

---

## Deskripsi Program

Program ini mengimplementasikan dua class yaitu **Point2D** dan **Triangle** untuk menentukan tipe segitiga berdasarkan koordinat tiga titik dalam ruang 2D/3D. Program dapat mendeteksi empat tipe segitiga:

- **Sama Sisi** — ketiga sisinya sama panjang
- **Sama Kaki** — tepat dua sisi sama panjang
- **Siku-Siku** — memenuhi teorema Pythagoras (a² + b² = c²)
- **Sembarang** — tidak ada sisi yang sama panjang

---

## Desain Class

### Hierarki & Relasi

```
Point2D   ←   digunakan oleh   →   Triangle
```

Program menggunakan **namespace `geo`** untuk mengorganisasi seluruh class.

---

### 1. Class `Point2D`

Merepresentasikan sebuah titik dalam ruang dengan koordinat x, y, z.

**Atribut:**
| Nama | Tipe | Keterangan |
|------|------|------------|
| `_x` | `float` | Koordinat sumbu X |
| `_y` | `float` | Koordinat sumbu Y |
| `_z` | `float` | Koordinat sumbu Z |

**Method:**
| Nama | Keterangan |
|------|------------|
| `GetX(), GetY(), GetZ()` | Getter koordinat |
| `SetX(), SetY(), SetZ()` | Setter koordinat |
| `distanceTo(other)` | Hitung jarak Euclidean ke titik lain |
| `operator+, -, *` | Operator aritmatika antar titik |

> ⚠️ **Bug Fix:** Pada template asli, `SetY()` dan `SetZ()` salah mengassign ke `_x` — sudah diperbaiki menjadi `_y` dan `_z`.

---

### 2. Class `Triangle`

Merepresentasikan segitiga yang dibentuk oleh tiga titik Point2D.

**Atribut:**
| Nama | Tipe | Keterangan |
|------|------|------------|
| `_t1` | `Point2D` | Titik pertama segitiga |
| `_t2` | `Point2D` | Titik kedua segitiga |
| `_t3` | `Point2D` | Titik ketiga segitiga |

**Method:**
| Nama | Keterangan |
|------|------------|
| `sideA()` | Panjang sisi antara t1 dan t2 |
| `sideB()` | Panjang sisi antara t2 dan t3 |
| `sideC()` | Panjang sisi antara t1 dan t3 |
| `TriangleType()` | Mengembalikan string tipe segitiga |

---

## Logika Pendeteksian Tipe Segitiga

### Rumus Jarak Euclidean

$$d = \sqrt{(x_2-x_1)^2 + (y_2-y_1)^2 + (z_2-z_1)^2}$$

### Alur Pengecekan

```
Hitung sisi a, b, c
        │
        ▼
   a == b == c ?  ──── YES ──→  "sama sisi"
        │ NO
        ▼
  a²+b²=c² atau   ──── YES ──→  "siku-siku"
  kombinasi lain?
        │ NO
        ▼
  a==b atau b==c  ──── YES ──→  "sama kaki"
  atau a==c ?
        │ NO
        ▼
     "sembarang"
```

> Perbandingan float menggunakan **epsilon = 1e-4** untuk menghindari error presisi floating point.

---

## Struktur File

```
assignment3/
├── Makefile
├── README.md
├── REPORT.md
└── src/
    ├── main.cpp
    ├── point2d.cpp
    ├── triangles.cpp
    └── include/
        ├── point2d.hpp
        └── triangle.hpp
```

---

## Contoh Input & Output

### Format Input
```
N
x1 y1 z1  x2 y2 z2  x3 y3 z3   ← titik segitiga ke-1
...                              ← ulangi N kali
```

### Contoh Input
```
4
0 0 0  6 0 0  3 4 0
0 0 0  1 0 0  0.5 0.866 0
0 0 0  3 0 0  0 4 0
0 0 0  1 0 0  2 3 0
```

### Output
```
sama kaki
sama sisi
siku-siku
sembarang
```

### Penjelasan Output

| Segitiga | Titik | Sisi | Tipe |
|----------|-------|------|------|
| 1 | (0,0,0), (6,0,0), (3,4,0) | 6, 5, 5 | sama kaki |
| 2 | (0,0,0), (1,0,0), (0.5,0.866,0) | 1, 1, 1 | sama sisi |
| 3 | (0,0,0), (3,0,0), (0,4,0) | 3, 5, 4 → 3²+4²=5² | siku-siku |
| 4 | (0,0,0), (1,0,0), (2,3,0) | 1, √10, √13 | sembarang |

---

## Konsep OOP yang Diimplementasikan

- **Encapsulation** — atribut `private`, diakses via getter/setter
- **Operator Overloading** — operator `+`, `-`, `*` pada Point2D
- **Custom Namespace `geo`** — semua class dibungkus dalam namespace `geo`
- **STL Vector** — `vector<Triangle>` digunakan untuk menyimpan banyak segitiga

---

## Kesimpulan

Program berhasil mengimplementasikan class `Point2D` dan `Triangle` dalam namespace `geo` untuk mendeteksi tipe segitiga. Pengecekan dilakukan secara berurutan: sama sisi → siku-siku → sama kaki → sembarang, dengan epsilon untuk menangani presisi float. Bug pada template asli (`SetY`/`SetZ` mengassign ke `_x`) juga berhasil diperbaiki.
