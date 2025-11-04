INSERT INTO Spells (
    name, level, school, cast_time, range, components, description
) VALUES 
    ('Guidance', 0, 2, '1 action', 'Touch', 'V,S', 
    'You touch one willing creatture. Once before the spell ends, the target can roll a d4 and add the number rolled to one ability check of its choice. It can roll the die before or after making the ability check. The spell then ends.'),
    ('Toll the Dead', 0, 6, '1 action', '60 feet', 'V,S', 
    'You point at one creature you can see within range, and the sound of a dolorous bell fills the air around it for a moment. The target must succeed on a Wisdom saving throw or take 1d8 nectrotic damage. If the target is missing any of its hit points, it instead takes 1d12 necrotic damage. \n The spells damage increasses by one die when you reach 5th level, 11th level, and 17th level.');
