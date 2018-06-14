INSERT INTO "OrmasSchema".relation_type(
            relation_type_id, relation_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'IS EXPEDITOR FOR', 'Expeditor for this client');
INSERT INTO "OrmasSchema".relation_type(
            relation_type_id, relation_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'IS MANAGER FOR', 'Managing');
