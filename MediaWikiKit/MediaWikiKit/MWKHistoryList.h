
#import "MWKList.h"
#import "MWKHistoryEntry.h"

@class MWKTitle;
@class MWKDataStore;

NS_ASSUME_NONNULL_BEGIN

@interface MWKHistoryList : MWKList<MWKHistoryEntry*>

/**
 *  Create history list and connect with data store.
 *  Will import any saved data from the data store on initialization
 *
 *  @param dataStore The data store to use for retrival and saving
 *
 *  @return The history list
 */
- (instancetype)initWithDataStore:(MWKDataStore*)dataStore;

@property (nonatomic, weak, readonly) MWKDataStore* dataStore;

- (MWKHistoryEntry* __nullable)entryForTitle:(MWKTitle*)title;

- (MWKHistoryEntry*)mostRecentEntry;

/**
 *  Add a page to the user history.
 *
 *  Calling this on a page already in the history will simply update its @c date.
 *
 *  @param title           The title of the page to add
 *  @param discoveryMethod The method of discovery. MWKHistoryDiscoveryMethodUnknown is ignored if updating an existing                 
 *                         entry.
 */
- (void)addPageToHistoryWithTitle:(MWKTitle*)title
                  discoveryMethod:(MWKHistoryDiscoveryMethod)discoveryMethod;

/**
 *  Save the scroll position of a page
 *
 *  @param scrollposition The scroll position to save
 *  @param title          The title of the page
 *
 *  @return The task. The result is the MWKHistoryEntry.
 */
- (void)savePageScrollPosition:(CGFloat)scrollposition toPageInHistoryWithTitle:(MWKTitle*)title;

/**
 *  Remove a page from the user history
 *
 *  @param title The title of the page to remove
 */
- (void)removePageFromHistoryWithTitle:(MWKTitle*)title;

/**
 *  Remove the given history entries from the history
 *
 *  @param historyEntries An array of instances of MWKHistoryEntry
 */
- (void)removeEntriesFromHistory:(NSArray*)historyEntries;

/**
 *  Remove all history items.
 */
- (void)removeAllEntriesFromHistory;

- (NSArray*)dataExport;

@end

NS_ASSUME_NONNULL_END

