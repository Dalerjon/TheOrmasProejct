INSERT INTO "OrmasSchema".divisions(
            division_id, division_name, division_code)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Производство', 'PRODUCTION');
INSERT INTO "OrmasSchema".divisions(
            division_id, division_name, division_code)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Реализация', 'RELEASE');
INSERT INTO "OrmasSchema".divisions(
            division_id, division_name, division_code)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Администрация', 'ADMINISTRATION');
