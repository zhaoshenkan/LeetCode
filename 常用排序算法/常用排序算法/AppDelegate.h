//
//  AppDelegate.h
//  常用排序算法
//
//  Created by 赵申侃 on 2018/12/13.
//  Copyright © 2018 赵申侃. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

