-- SpellSchool: Abjuration, Conjuration, Divination, Enchantment, Evocation, Illusion, Necromancy, Transmutation
INSERT INTO Spells (
    name, level, school, cast_time, range, components, duration, description
) VALUES 
    ('Guidance', 0, 2, '1 action', 'Touch', 'V,S', 'C, 1 minute',
    'You touch one willing creatture. Once before the spell ends, the target can roll a d4 and add the number rolled to one ability check of its choice. It can roll the die before or after making the ability check. The spell then ends.'),
    ('Thaumaturgy', 0, 7, '1 action', '30 feet', 'V', '1 minute',
    'You manifest a minor wonder, a sign of superntural power, within range. You create one magical effect within range (thunderous voice, flame effect, harmless tremors for minute, inst. sound, slam door, alter eyes).'),
    ('Toll the Dead', 0, 6, '1 action', '60 feet', 'V,S', 'Instantaneous',
    'You point at one creature you can see within range, and the sound of a dolorous bell fills the air around it for a moment. The target must succeed on a Wisdom saving throw or take 1d8 nectrotic damage. If the target is missing any of its hit points, it instead takes 1d12 necrotic damage. 
    The spells damage increasses by one die when you reach 5th level, 11th level, and 17th level.'),
    ('Bless', 1, 3, '1 action', '30 feet', 'V,S,M', 'C, 1 minute',
    'You bless up to three creatures of your choice within range. Whenever a target makes an attack roll or a saving throw before the spell ends, the target can roll a d4 and add the number rolled to the attack roll or saving throw.'),
    ('Healing Word', 1, 4, '1 bonus action', '60 feet', 'V', 'Instantaneous',
    'A creature of your choice that you can see within range regains points equal to 1d4 + your spellcasting abuluty modifier. This spell has no effect on undead or constructs.
    When you cast this spell using a spell slot of 2nd level or higher, the healing increases by 1d4 for each slot level above 1st.'),
    ('Guiding Bolt', 1, 4, '1 action', '120 feet', 'V,S', '1 round',
    'A flash of light streaks toward a creature of your choice within range. Make a ranged spell attack against the target. On a hit, the target takes 4d6 radiant damage, and the next attack roll made against this target before the end of your next turn has advantage, thanks to the mystical dim light glitetering on the target until then.
    When you cast this spell using a spell slot of 2nd level or higher, the damage increases by 1d6 for each slot level above 1st.'),
    ('Heroism', 1, 3, '1 action', 'Touch', 'V,S', 'C, 1 minute',
    'A willing creature you touch is imbued with bravery. Until the spell ends, the creature is immune to being frightened and gains temporary hit points equal to your spellcasting ability modifier at the start of each of its turns. When the spell ends, the target loses any remaining temporary hit points from this spell.
    When you cast this spell using a spell slot of 2nd level or higher, you can target one additional creature for each slot level above 1st'),
    ('Command', 1, 3, '1 action', '60 feet', 'V', '1 round',
    'You speak a one-word command to a creature you can see within range. The target must succeed on a Wisdom saving throw or follow the command on its next turn. The spell has no effect if the target is undead, if it does not understand your language, or if your command is directly harmful to it.
    When you cast this spell using a spell slot of 2nd level or higher, you can affect one additional creature for each slot level above 1st. The creatures must be within 30 feet of each other when you target them.');
