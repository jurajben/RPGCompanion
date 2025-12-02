CREATE TABLE IF NOT EXISTS "Spells" 
(
    `id` INTEGER PRIMARY KEY,
    `name` TEXT NOT NULL,
    `level` INT NOT NULL,
    `school` INT NOT NULL, 
    `cast_time` TEXT NOT NULL,
    `range` TEXT NOT NULL,
    `components` TEXT NOT NULL,
    `duration` TEXT NOT NULL,
    `description` TEXT
);
-- SpellSchool: Abjuration, Conjuration, Divination, Enchantment, Evocation, Illusion, Necromancy, Transmutation

CREATE TABLE IF NOT EXISTS "CharacterSpells" 
(
    `id` INTEGER PRIMARY KEY,
    `character_id` INT NOT NULL,
    `spell_id` INT NOT NULL
)
