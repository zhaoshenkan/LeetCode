//
//  ViewController.m
//  常用排序算法
//
//  Created by 赵申侃 on 2018/12/13.
//  Copyright © 2018 赵申侃. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSMutableArray *arr = [@[@5,@6,@1,@2,@8,@7,@9,@4,@3] mutableCopy];
//    [self quickSort:arr leftIndex:0 rightIndex:(arr.count - 1)];
    [self inserSort:arr];
}

//快排
- (void)quickSort:(NSMutableArray *)arr leftIndex:(NSInteger)leftIndex rightIndex:(NSInteger)rightIndex
{
    if (leftIndex >= rightIndex) {
        return;
    }
    NSInteger key = [arr[leftIndex] integerValue];
    NSInteger i = leftIndex;
    NSInteger j = rightIndex;
    
    while (i < j) {
        
        if (i < j && key <= [arr[j] integerValue] ) {
            j -- ;
        }
        arr[i] = arr[j];
        if (i < j && key >= [arr[i] integerValue]) {
            i ++ ;
        }
        arr[j] = arr[i];
        //        NSLog(@"i = %ld,j = %ld,arr[i] = %ld,arr[j] = %ld arr = %@",i,j,[arr[i] integerValue],[arr[j] integerValue],arr);
    }
    arr[i] = [NSNumber numberWithInteger:key];
    
    [self quickSort:arr leftIndex:leftIndex rightIndex:i - 1];
    [self quickSort:arr leftIndex:i + 1 rightIndex:rightIndex];
}

//插入排序
- (void)inserSort:(NSMutableArray *)array{
    //插入排序的原理：始终定义第一个元素为有序的，将元素逐个插入到有序排列之中，其特点是要不断的
    
    //移动数据，空出一个适当的位置，把待插入的元素放到里面去。
    for (int i = 0; i < array.count; i++) {
        NSNumber *temp = array[i];
        //temp 为待排元素 i为其位置 j为已排元素最后一个元素的位置（即取下一个元素，在已经排好序的元素序列中从后向前扫描）
        int j = i-1;
        //当j < 0 时， i 为第一个元素 该元素认为已经是排好序的 所以不进入while循环
        //  [array[j] compare:temp] == NSOrderedDescending与[array[j] intValue] > [temp intValue] 作用相同
        while (j >= 0 && [array[j] compare:temp] == NSOrderedDescending) {
            //如果已经排好序的序列中元素大于新元素，则将该元素往右移动一个位置
            [array replaceObjectAtIndex:j+1 withObject:array[j]];
            j--;
        }
        //跳出while循环时，j的元素小于或等于i的元素(待排元素)。插入新元素 i= j+1
        [array replaceObjectAtIndex:j+1 withObject:temp];
        NSLog(@"插入排序排序中:%@",array);
    }
}

@end
