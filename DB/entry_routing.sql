INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Начислена задолженность учредителя по вкладу в уставной капитал', 10600, 33010);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесены материалы в счёт взносов в уставный капитал', 10720, 10600);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесение в кассу организации наличных денежных средств в погашение задолженности учредителей по вкладам в уставный капитал', 10110, 10600);
	INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесение(Перечисление) денежных средств в счета организации в погашение задолженности учредителей по вкладам в уставный капитал', 10210, 10600);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесены учредителями в счет вклада в уставный капитал основные средства', 11000, 10600);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесены учредителями в счет вклада в уставный капитал основные средства(Здание и сооружение)', 11010, 10600);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесены учредителями в счет вклада в уставный капитал основные средства(Машины и оборудование)', 11020, 10600);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесены учредителями в счет вклада в уставный капитал основные средства(Конторское оборудование)', 11030, 10600);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесены учредителями в счет вклада в уставный капитал основные средства(Мебель и принадлежности)', 11040, 10600);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесены учредителями в счет вклада в уставный капитал основные средства(Транспортные средства)', 11050, 10600);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесены учредителями в счет вклада в уставный капитал основные средства(Благоустройство арендованной собственности)', 11060, 10600);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесены учредителями в счет вклада в уставный капитал основные средства(Благоустройство земельных участков)', 11070, 10600);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесены учредителями в счет вклада в уставный капитал основные средства(Прочие основные средства)', 11080, 10600);
INSERT INTO "OrmasSchema".entry_routing(
            entry_routing_id, operation_name, debit, credit)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'Внесены учредителями в счет вклада в уставный капитал основные средства(Прочие основные средства)', 11090, 10600);
