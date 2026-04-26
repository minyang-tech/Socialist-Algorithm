Socialist Algorithm. 

사회주의자 알고리즘

![C++](https://img.shields.io/badge/language-C%2B%2B-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Status](https://img.shields.io/badge/status-experimental-orange)
![Performance](https://img.shields.io/badge/performance-adaptive-red)

A hybrid sorting algorithm based on adaptive redistribution and local competition.  
적응형 재분배와 지역적 정렬을 결합한 하이브리드 정렬 알고리즘입니다.  

# Overview

This algorithm redistributes elements globally using sampled boundaries,  
then resolves local ordering inside each group.

이 알고리즘은 샘플 기반 경계를 이용해 데이터를 전체적으로 재배치한 뒤,  
각 그룹 내부에서 정렬을 수행합니다.

# Key Idea

1. Global redistribution (approximate positioning)  

2. Local sorting (refinement inside buckets)  

3. 전체 재배치 (대략적인 위치 정렬)  

4. 지역 정렬 (버킷 내부 정밀 정렬)  

# Features

- Adaptive partitioning using sampling  

- Counting sort fallback for small ranges  

- Recursive refinement for dense buckets  

- 샘플 기반 적응형 분할  

- 범위가 좁을 때 counting sort 사용

- 과밀 버킷 재귀 처리

# Complexity

Case| Time
Average| O(n)
Worst| O(n log n)

# Benchmark

Example result (n = 100000):

std::sort: 12000 us
socialist_sort: 8500 us

Performs well on distribution-heavy datasets.  
특정 분포를 가진 데이터에서 높은 성능을 보입니다. 

# Usage

vector<int> arr = {5, 3, 1, 4, 2};
socialist_sort(arr);

# File Structure

socialist_sort.cpp   // main algorithm
benchmark.cpp        // performance test

> [!NOTE]
> This algorithm is inspired by the idea of "redistribution",  
> where elements are globally balanced before local competition.
>
> 이 알고리즘은 "재분배" 개념에서 영감을 받아,  
> 전체 균형을 맞춘 뒤 지역적으로 정렬합니다.

# License

MIT License

The Minyang Tech standard end-user license agreement does not apply.  

민양테크 표준 최종 사용자 라이선스 계약이 적용되지 않습니다.