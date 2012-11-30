/**
 * Copyright (c) 2008, 2012, Pecunia Project. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#import <Cocoa/Cocoa.h>

@class BankAccount;
@class ClassificationContext;
@class Category;
@class StatCatAssignment;

@interface BankStatement : NSManagedObject {
	
//	BankAccount *account;
//	BOOL		isNew;
}

-(BOOL)matches: (BankStatement*)stat;
-(BOOL)matchesAndRepair: (BankStatement*)stat;

-(NSObject*)classify;
-(NSComparisonResult)compareValuta: (BankStatement*)stat;

-(void)assignToCategory:(Category*)cat;
-(void)assignAmount: (NSDecimalNumber*)value toCategory:(Category*)cat;
-(void)updateAssigned;
-(BOOL)hasAssignment;
-(NSDecimalNumber*)residualAmount;
-(StatCatAssignment*)bankAssignment;
-(void)changeValueTo:(NSDecimalNumber*)val;

-(void)addToAccount: (BankAccount*)account;

-(NSString*)floatingPurpose;

+(void)setClassificationContext: (ClassificationContext*)cc;
+(void)initCategoriesCache;

@property (nonatomic, strong) NSDate *valutaDate;
@property (nonatomic, strong) NSDate *date;

@property (nonatomic, strong) NSDecimalNumber *value;
@property (nonatomic, strong) NSDecimalNumber *nassValue;
@property (nonatomic, strong) NSDecimalNumber *charge;
@property (nonatomic, strong) NSDecimalNumber *saldo;


@property (nonatomic, strong) NSString *remoteName;
@property (nonatomic, strong) NSString *remoteIBAN;
@property (nonatomic, strong) NSString *remoteBIC;
@property (nonatomic, strong) NSString *remoteBankCode;
@property (nonatomic, strong) NSString *remoteBankLocation;
@property (nonatomic, strong) NSString *remoteBankName;
@property (nonatomic, strong) NSString *remoteAccount;
@property (nonatomic, strong) NSString *remoteCountry;
@property (nonatomic, strong) NSString *purpose;
@property (nonatomic, strong) NSString *localSuffix;
@property (nonatomic, strong) NSString *remoteSuffix;

@property (nonatomic, strong, readonly) NSString * categoriesDescription;

@property (nonatomic, strong) NSString *localBankCode, *localAccount;
@property (nonatomic, strong) NSString *customerReference;
@property (nonatomic, strong) NSString *bankReference;
@property (nonatomic, strong) NSString *transactionText;
@property (nonatomic, strong) NSNumber *transactionCode;
@property (nonatomic, strong) NSString *currency;
@property (nonatomic, strong) NSString *primaNota;
@property (unsafe_unretained, nonatomic, readonly) NSString *note;

@property (nonatomic, strong) NSString *additional;
@property (nonatomic, strong) NSNumber *hashNumber;
@property (nonatomic, strong) NSNumber *isAssigned;		// assigned to >= 100%
@property (nonatomic, strong) NSNumber *isManual;
@property (nonatomic, strong) NSNumber *isStorno;
@property (nonatomic, strong) NSNumber *isNew;

@property (nonatomic, strong) NSString * ref1;
@property (nonatomic, strong) NSString * ref2;
@property (nonatomic, strong) NSString * ref3;
@property (nonatomic, strong) NSString * ref4;

@property (nonatomic, strong) BankAccount *account;

@end

// coalesce these into one @interface BankStatement (CoreDataGeneratedAccessors) section
@interface BankStatement (CoreDataGeneratedAccessors)
@end