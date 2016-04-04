//
//  CXBaseAction.h
//

#import <Foundation/Foundation.h>

extern NSString *const kCXActionDidLoadNotifaction;         /*!< 动作被加载 */
extern NSString *const kCXActionDidSuspendNotifaction;      /*!< 动作被挂起 */
extern NSString *const kCXActionDidResumeNotifaction;       /*!< 动作被恢复 */
extern NSString *const kCXActionDidLeaveNotifaction;        /*!< 动作被卸载 */
extern NSString *const kCXActionDidDestroyNotifaction;      /*!< 动作被销毁 */

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 动作类，定义程序的每一个环节，一个程序只有一个动作栈，一个动作栈不允许中间插入新动作
 */
@interface CXBaseAction : NSObject

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 使用该动作作为根动作，新动作将会发送kCXActionDidLoadNotifaction通知
 *  @param actionClass 根动作类名
 */
+(CXBaseAction*) launchAsRootAction:(Class)actionClass;

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 进入新动作，该动作将发送kCXActionDidSuspendNotifaction通知
 *         新动作将会发送kCXActionDidLoadNotifaction通知
 *  @param actionClass 新动作类名
 */
-(void) enterAction:(Class)actionClass;

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 离开本动作，该动作将发送kCXActionDidLeaveNotifaction和kCXActionDidDestroyNotifaction通知，
 *         子动作只发送kCXActionDidDestroyNotifaction通知
 */
-(void) leaveAction;

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 销毁子动作，子动作将发送kCXActionDidDestroyNotifaction通知，
 *         该动作会发送kCXActionDidResumeNotifaction通知
 */
-(void) destroyChildAction;

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 获取子动作
 *  @param className 子动作类名
 *  @return 获取子动作
 */
-(CXBaseAction*) childActionForClass:(Class)className;

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 获取根动作
 *  @return 获取根动作
 */
-(CXBaseAction*) rootAction;

#pragma mark - 子类需要重载

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 动作被加载
 */
-(void) actionDidLoad;

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 动作被挂起
 */
-(void) actionDidSuspend;

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 动作被恢复
 */
-(void) actionDidResume;

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 动作被卸载
 */
-(void) actionDidLeave;

/**
 *  @author LeiQiao, 16/04/02
 *  @brief 动作被销毁
 */
-(void) actionDidDestroy;

@end