-- White Bear
DELETE FROM `item_loot_template` WHERE (`entry`='44751');

INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (44751, 17202, 30, 1, 1, 3, 4);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (44751, 43962, 0.5, 1, 0, 1, 1);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (44751, 44749, 30, 1, 1, 8, 12);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES (44751, 44750, 30, 1, 1, 5, 12);

-- Raven Lord
UPDATE `creature_loot_template` SET `groupid`='0' WHERE (`entry`='23035') AND (`item`='32768')