INSERT INTO "OrmasSchema".status(
            status_id, status_code, status_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0001', 'SUCCESS', 'Any operations which ends with success');
INSERT INTO "OrmasSchema".status(
            status_id, status_code, status_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0002', 'FAIL', 'Any operations which ends with fail');
INSERT INTO "OrmasSchema".status(
            status_id, status_code, status_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0003', 'IN PROGRESS', 'In progress status is informed that operation is realizing');
INSERT INTO "OrmasSchema".status(
            status_id, status_code, status_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0004', 'DONE', 'Any action is done');
INSERT INTO "OrmasSchema".status(
            status_id, status_code, status_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0005', 'EXECUTED', 'Execution status is shown that employee done his job');
INSERT INTO "OrmasSchema".status(
            status_id, status_code, status_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0006', 'ERROR', 'Operation or action was ended with error');
INSERT INTO "OrmasSchema".status(
            status_id, status_code, status_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0007', 'ORDERED', 'Status of ordering');
INSERT INTO "OrmasSchema".status(
            status_id, status_code, status_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0008', 'TO RETURN', 'Status of ordering');
INSERT INTO "OrmasSchema".status(
            status_id, status_code, status_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0009', 'WRITEOFFED', 'Status of ordering');
INSERT INTO "OrmasSchema".status(
            status_id, status_code, status_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0010', 'PRODUCED', 'Status of product production');
INSERT INTO "OrmasSchema".status(
            status_id, status_code, status_name, comment)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '0011', 'IN STOKE', 'Status of product production');