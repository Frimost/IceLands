-- Entrys
SET @NPC_ENTRY := 68696;-- 68696
SET @NPC_ENTRY_10H := @NPC_ENTRY+1;
SET @NPC_ENTRY_25N := @NPC_ENTRY+2;
SET @NPC_ENTRY_25H := @NPC_ENTRY+3;
SET @NPC_ENTRY_ADD := 68709;


-- Creature template ---
-- base (10N)
DELETE FROM `creature_template` WHERE `entry` IN (@NPC_ENTRY,@NPC_ENTRY_10H,@NPC_ENTRY_25N,@NPC_ENTRY_25H);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES 
(@NPC_ENTRY, @NPC_ENTRY_25N, @NPC_ENTRY_10H, @NPC_ENTRY_25H, 0, 0, 26638, 0, 0, 0, 'Jon Snow', 'Winter is coming', '', 0, 83, 83, 0, 21, 21, 0, 1, 1.14286, 1, 3, 550, 700, 0, 810, 35, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 6, 108, @NPC_ENTRY, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 500, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8461332, 0, 'boss_custom_icc', 1),
-- (10H)
(@NPC_ENTRY_10H, 0, 0, 0, 0, 0, 26638, 0, 0, 0, 'Jon Snow', 'Winter is coming', '', 0, 83, 83, 0, 21, 21, 0, 1, 1.14286, 1, 3, 550, 700, 0, 810, 35, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 6, 108, @NPC_ENTRY_10H, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 500, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8461332, 0, 'boss_custom_icc', 1),
-- (25N)
(@NPC_ENTRY_25N, 0, 0, 0, 0, 0, 26638, 0, 0, 0, 'Jon Snow', 'winter is comming', '', 0, 83, 83, 0, 21, 21, 0, 1, 1.14286, 1, 3, 550, 700, 0, 810, 35, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 6, 108, @NPC_ENTRY_25N, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 500, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8461332, 0, 'boss_custom_icc', 1),
-- (25H)
(@NPC_ENTRY_25H, 0, 0, 0, 0, 0, 26638, 0, 0, 0, 'Jon Snow', 'winter is comming', '', 0, 83, 83, 0, 21, 21, 0, 1, 1.14286, 1, 3, 550, 700, 0, 810, 35, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 6, 108, @NPC_ENTRY_25H, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 500, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8461332, 0, 'boss_custom_icc', 1),
-- add
(@NPC_ENTRY_ADD, 0, 0, 0, 0, 0, 26725, 0, 0, 0, 'Vaal', 'winter is comming', '', 0, 83, 83, 0, 21, 21, 0, 1, 1.14286, 1, 3, 550, 700, 0, 810, 35, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 6, 108, @NPC_ENTRY_25H, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 500, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8461332, 0, 'custom_add_icc', 1);

-- HP & damage
UPDATE `creature_template` SET `Health_mod` = 530 , `dmg_multiplier` = 35 WHERE `entry` = @NPC_ENTRY;
UPDATE `creature_template` SET `Health_mod` = 1730,`dmg_multiplier` = 45 WHERE `entry` = @NPC_ENTRY_25N;
UPDATE `creature_template` SET `Health_mod` = 780,`dmg_multiplier` = 45 WHERE `entry` = @NPC_ENTRY_10H;
UPDATE `creature_template` SET `Health_mod` = 2280,`dmg_multiplier` = 55 WHERE `entry` = @NPC_ENTRY_25H;
UPDATE `creature_template` SET `Health_mod` = 320,`dmg_multiplier` = 20, `unit_class` = 2, `Mana_mod`= 30 WHERE `entry` = @NPC_ENTRY_ADD;

-- SPAWN
DELETE FROM `creature` WHERE `id` = @NPC_ENTRY;
INSERT INTO `creature` VALUES
('',@NPC_ENTRY,'631','15','0','0','2352','-327.695','2211.15','199.974','6.27942','604800','0','0','0','0','0','0','0','0','0');
-- Creature Loot --
-- references loots, solo TDB, cuidado acá no se puede pisar otro npc 
CALL sp_get_ref_id('RAID_CRE',@NPC_REF_10N);
-- set @NPC_REF_10N := 34361;

DELETE FROM `creature_loot_template` WHERE `entry` IN (@NPC_ENTRY,@NPC_ENTRY_10H,@NPC_ENTRY_25N,@NPC_ENTRY_25H);
INSERT INTO `creature_loot_template` VALUES
-- 10N 
(@NPC_ENTRY,49426,100,1,0,2,2),
(@NPC_ENTRY,1,100,1,0,-(@NPC_REF_10N),2),
-- 10H
(@NPC_ENTRY_10H,49426,100,1,0,2,2),
(@NPC_ENTRY_10H,1,100,1,0,-(@NPC_REF_10N+1),2),
-- 25N
(@NPC_ENTRY_25N,49426,100,1,0,2,2),
(@NPC_ENTRY_25N,1,100,1,0,-(@NPC_REF_10N+2),2),
-- 25H
(@NPC_ENTRY_25H,49426,100,1,0,2,2),
(@NPC_ENTRY_25H,1,100,1,0,-(@NPC_REF_10N+3),2);
-- Reference loot --
DELETE FROM reference_loot_template WHERE entry IN (@NPC_REF_10N,@NPC_REF_10N+1,@NPC_REF_10N+2,@NPC_REF_10N+3);
INSERT INTO reference_loot_template VALUES
-- 10N
(@NPC_REF_10N,50793,0,1,1,1,1),
(@NPC_REF_10N,50787,0,1,1,1,1),
(@NPC_REF_10N,50340,0,1,1,1,1),
(@NPC_REF_10N,50794,0,1,1,1,1),
(@NPC_REF_10N,50788,0,1,1,1,1),
(@NPC_REF_10N,50789,0,1,1,1,1),
(@NPC_REF_10N,50792,0,1,1,1,1),
(@NPC_REF_10N,50791,0,1,1,1,1),
(@NPC_REF_10N,50796,0,1,1,1,1),
(@NPC_REF_10N,50797,0,1,1,1,1),
(@NPC_REF_10N,50795,0,1,1,1,1),
(@NPC_REF_10N,50790,0,1,1,1,1),
-- 10H
(@NPC_REF_10N+1,51910,0,1,1,1,1),
(@NPC_REF_10N+1,51916,0,1,1,1,1),
(@NPC_REF_10N+1,50345,0,1,1,1,1),
(@NPC_REF_10N+1,51912,0,1,1,1,1),
(@NPC_REF_10N+1,51914,0,1,1,1,1),
(@NPC_REF_10N+1,51908,0,1,1,1,1),
(@NPC_REF_10N+1,51909,0,1,1,1,1),
(@NPC_REF_10N+1,51911,0,1,1,1,1),
(@NPC_REF_10N+1,51915,0,1,1,1,1),
(@NPC_REF_10N+1,51913,0,1,1,1,1),
(@NPC_REF_10N+1,51907,0,1,1,1,1),
(@NPC_REF_10N+1,51906,0,1,1,1,1),
-- 25N
(@NPC_REF_10N+2,50352,0,1,1,1,1),
(@NPC_REF_10N+2,50008,0,1,1,1,1),
(@NPC_REF_10N+2,50001,0,1,1,1,1),
(@NPC_REF_10N+2,50009,0,1,1,1,1),
(@NPC_REF_10N+2,50359,0,1,1,1,1),
(@NPC_REF_10N+2,50005,0,1,1,1,1),
(@NPC_REF_10N+2,50411,0,1,1,1,1),
(@NPC_REF_10N+2,50002,0,1,1,1,1),
(@NPC_REF_10N+2,50011,0,1,1,1,1),
(@NPC_REF_10N+2,49999,0,1,1,1,1),
(@NPC_REF_10N+2,49998,0,1,1,1,1),
(@NPC_REF_10N+2,50003,0,1,1,1,1),
(@NPC_REF_10N+2,50000,0,1,1,1,1),
(@NPC_REF_10N+2,50006,0,1,1,1,1),
(@NPC_REF_10N+2,50010,0,1,1,1,1);
-- 25H TODO: add loot

-- set script  & equip --
UPDATE creature_template SET ScriptName = 'boss_custom_icc',equipment_id = 2352 WHERE entry IN (@NPC_ENTRY,@NPC_ENTRY_10H,@NPC_ENTRY_25N,@NPC_ENTRY_25H);
-- SAY TODO: mejorar los textos
DELETE FROM `creature_text` WHERE entry =@NPC_ENTRY;
INSERT INTO `creature_text` VALUES
(@NPC_ENTRY,1,0,'¡¡ winter is comming !!',1,0,0,0,0,0,''),
(@NPC_ENTRY,2,0,'Haaa ',1,0,0,0,0,0,''),
(@NPC_ENTRY,3,0,' >:D ',1,0,0,0,0,0,'');
