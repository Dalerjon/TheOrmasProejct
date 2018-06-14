INSERT INTO "OrmasSchema".account_type(
            account_type_id, account_type_name, account_type_number, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'PASSIVE', 0, '');
INSERT INTO "OrmasSchema".account_type(
            account_type_id, account_type_name, account_type_number, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'ACTIVE', 1, '');
	INSERT INTO "OrmasSchema".account_type(
            account_type_id, account_type_name, account_type_number, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'ACTIVE/PASSIVE', 2, '');
