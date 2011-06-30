-- Fix ICC bosses immunities, needfeedback
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask` |1|2|4|8|16|32|64|128|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|8388608|67108864|536870912 WHERE `entry` IN
(36597,39166,39167,39168, -- The Lich King
36612,37957,37958,37959, -- Lord Marrowgar
36626,37504,37505,37506, -- Festergut
36627,38390,38549,38550, -- Rotface
36678,38431,38585,38586, -- Professor Putricide
36853,38265,38266,38267, -- Sindragosa
36855,38106,38296,38297, -- Lady Deathwhisper
37813,38402,38582,38583, -- Deathbringer Saurfang
37955,38434,38435,38436, -- Blood-Queen Lana'thel
37970,38401,38784,38785,  -- Prince Valanar
37972,38399,38769,38770, -- Prince Keseleth
37973,38400,38771,38772); -- Prince Taldaram