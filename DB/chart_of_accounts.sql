INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10100', 'Денежные средства в кассе', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10110', 'Денежные средства в национальной валюте', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10120', 'Денежные средства в иностранной валюте', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10130', 'Денежные документы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10140', 'Денежные эквиваленты', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10200', 'Денежные средства в банке', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10210', 'Счета в национальной валюте', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10220', 'Счета в иностранной валюте в местных банках', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10230', 'Счета в зарубежных банках', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10240', 'Денежные средства в банках, ограниченных к использованию', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10250', 'Денежные средства в пути', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10300', 'Краткосрочные инвестиции', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE/PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10310', 'Долговые ценные бумаги', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10320', 'Долевые ценные бумаги', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10330', 'Займы выданные', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10340', 'Депозитные вклады', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10350', 'Текущая часть долгосрочных инвестиций', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10360', 'Прочие краткосрочные инвестиции', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10400', 'Торговая дебиторская задолженность', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE/PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10410', 'Счета к получению', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10420', 'Векселя к получению', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10430', 'Резервы по сомнительным долгам', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10500', 'Прочая дебиторская задолженность', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10510', 'Авансы, выданные поставщикам', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10520', 'Дебиторская задолженность персонала', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10530', 'Налоги, оплаченные авансом', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10540', 'Налоги, подлежащие возмещению', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10550', 'Проценты к получению', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10560', 'Дивиденды к получению', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10570', 'Текущая часть долгосрочной дебиторской задолженности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10580', 'Дебиторская задолженность дочерних (материнских) предприятий', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10590', 'Дебиторская задолженность по прочим операциям', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10600', 'Задолженность учредителей (участников) по вкладам в уставный капитал', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10700', 'Товарно-материальные запасы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE/PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10710', 'Товары', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE/PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10719', 'Нереализованная торговая наценка', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10720', 'Сырье и материалы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10730', 'Незавершенное производство', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10740', 'Готовая продукция', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10742', 'Готовая продукция в пути', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10750', 'Сельхозпродукция с биологических активов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10760', 'Топливо', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10770', 'Запасные части', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10780', 'Инвентарь и принадлежности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10790', 'Прочие запасы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10800', 'Расходы, оплаченные авансом', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10810', 'Услуги, оплаченные авансом', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10820', 'Аренда, оплаченная авансом', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10830', 'Прочие авансированные платежи', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10900', 'Внеоборотные активы для продажи', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10910', 'Основные средства, предназначенные для продажи', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10920', 'Краткосрочные активы прекращенной деятельности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '10930', 'Прочие внеоборотные активы для продажи', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11000', 'Основные средства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11010', 'Здания и сооружения', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11020', 'Машины и оборудование', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11030', 'Конторское оборудование', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11040', 'Мебель и принадлежности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11050', 'Транспортные средства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11060', 'Благоустройство арендованной собственности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11070', 'Благоустройство земельных участков', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11080', 'Прочие основные средства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11090', 'Незавершенное строительство', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11100', 'Накопленный износ основных средств', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11110', 'Накопленный износ – здание и сооружения', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11120', 'Накопленный износ – машины и оборудования', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11130', 'Накопленный износ – конторское оборудование', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11140', 'Накопленный износ – мебель и принадлежности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11150', 'Накопленный износ – транспортные средства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11160', 'Накопленный износ – благоустройство арендованной
собственности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11170', 'Накопленный износ – благоустройство земельных участков', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11180', 'Накопленный износ – прочие основные средства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11200', 'Природные ресурсы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11210', 'Месторождения минеральных руд', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11220', 'Месторождения углеводородов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11290', 'Накопленное истощение природных ресурсов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11300', 'Нематериальные активы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11310', 'Право пользования землей', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11320', 'Гудвилл', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11330', 'Патенты, лицензии, франшизы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11340', 'Торговые марки', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11350', 'Авторские права', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11360', 'Программные обеспечения', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11370', 'Прочие нематериальные активы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11390', 'Накопленная амортизация нематериальных активов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11400', 'Биологические активы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11410', 'Животные (потребляемые биологические активы)', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11420', 'Животные (плодоносящие биологические активы)', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11430', 'Растения (потребляемые биологические активы)', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11440', 'Плодоносящие растения', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11450', 'Биологические активы, учитываемые по фактическим затратам', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11460', 'Другие биологические активы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11500', 'Инвестиции в недвижимость', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11510', 'Здания и сооружения', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11520', 'Реконструкция объектов инвестиции в недвижимость', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11600', 'Долгосрочные инвестиции', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE/PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11610', 'Долговые ценные бумаги', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11620', 'Займы, выданные', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11630', 'Инвестиции в дочерние предприятия', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE/PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11640', 'Инвестиции в совместную деятельность', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11650', 'Инвестиции в ассоциированные предприятия', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11660', 'Прочие долгосрочные инвестиции', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11661', 'Дисконты (cкидки) по долгосрочным инвестициям', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11662', 'Премии (надбавки) по долгосрочным инвестициям', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11700', 'Отсроченные налоговые требования', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11800', 'Долгосрочная дебиторская задолженность', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11810', 'Долгосрочная дебиторская задолженность покупателей и
заказчиков', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11820', 'Векселя полученные', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11830', 'Долгосрочные отсроченные расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11840', 'Прочая долгосрочная дебиторская задолженность', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '11900', 'Долгосрочные активы прекращенной деятельности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22000', 'Торговая кредиторская задолженность', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22010', 'Счета к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22020', 'Краткосрочные векселя к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22030', 'Авансы полученные', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22040', 'Прочие счета к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22100', 'Краткосрочные долговые обязательства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22110', 'Банковские кредиты, займы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22120', 'Прочие кредиты, займы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22130', 'Текущая часть долгосрочных долговых обязательств', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22140', 'Прочие краткосрочные долговые обязательства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22141', 'Дисконты (скидки) по облигациям и векселям', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22142', 'Премии (надбавки) по облигациям', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22200', 'Краткосрочные начисленные обязательства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22210', 'Зарплата к выплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22220', 'Пенсионный налог к выплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22230', 'Подоходный налог к выплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22240', 'Социальный налог к выплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22250', 'Дивиденды к выплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22260', 'Проценты к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22270', 'Прочие начисленные расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22300', 'Налоги к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22310', 'Налог на прибыль к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22320', 'НДС к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22330', 'Акцизы к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22340', 'Налог на имущество к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22350', 'Дорожный налог к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22360', 'Налог на землю к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22370', 'Прочие налоги к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22400', 'Резервы предстоящих расходов и платежей', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22410', 'Резервы на оплату отпускных', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22420', 'Резервы на гарантийное обслуживание', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22430', 'Резервы судебных исков', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22440', 'Прочие начисленные резервы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22500', 'Прочие краткосрочные обязательства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22510', 'Обязательства перед учредителями', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22520', 'Кредиторская задолженность дочерних (материнских)
предприятий', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22530', 'Краткосрочные обязательства прекращенной деятельности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22600', 'Долгосрочные обязательства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22610', 'Облигации к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22620', 'Банковские кредиты, займы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22630', 'Прочие кредиты, займы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22640', 'Векселя к оплате', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22650', 'Обязательства по финансовой аренде', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22660', 'Долгосрочные обязательства прекращенной деятельности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22670', 'Прочие долгосрочные обязательства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22691', 'Дисконты (скидки) по долгосрочным облигациям', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22692', 'Премии (надбавки) по долгосрочным облигациям', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22700', 'Отсроченные доходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22710', 'Отсроченные доходы – гранты', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22720', 'Долгосрочные авансы, полученные', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22730', 'Прочие отсроченные доходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '22800', 'Отсроченные налоговые обязательства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33000', 'Объявленный(уставный) капитал', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33010', 'Простые акции', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33020', 'Привилегированные акции', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33030', 'Дополнительно оплаченный капитал', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33090', 'Выкупленные собственные акции', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33100', 'Добавочный капитал', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33110', 'Гранты и целевые финансирования', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33120', 'Корректировки по переоценке основных средств', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33130', 'Корректировки по переоценке прочих активов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33140', 'Курсовые разницы по операциям с иностранным
подразделениям', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33150', 'Безвозмездно полученные ценности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33160', 'Прочий добавочный капитал', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33200', 'Нераспределенная прибыль', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33210', 'Нераспределенная прибыль отчетного года', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33220', 'Нераспределенная прибыль прошлых лет', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33300', 'Резервный капитал', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '33400', 'Доля меньшинства', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '44000', 'Доходы от операционной деятельности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE/PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '44010', 'Доходы от реализации', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '44020', 'Прочие доходы от операционной деятельности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '44090', 'Возврат проданных товаров и скидки', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '44100', 'Доходы от биологических активов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '44110', 'Прибыль (убыток) от первоначального признания
биологических активов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '44120', 'Доход от сбора сельхозпродукции', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '44130', 'Прибыль (убыток) от изменения справедливой стоимости
биологических активов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55000', 'Себестоимость реализованных запасов, работ и услуг', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE/PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55010', 'Себестоимость реализации', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55020', 'Корректировка стоимости запасов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55030', 'Расходы по транспортировке запасов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55040', 'Расходы на переработку', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55050', 'Расходы на приобретение запасов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55100', 'Расходы по производству биологических активов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE/PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55200', 'Реализационные расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55210', 'Расходы на рекламу и содействие продаж', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55220', 'Расходы на оплату труда', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55230', 'Расходы по отчислениям в социальные фонды', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55240', 'Расходы по хранению и транспортировке', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55250', 'Расходы по безнадежным долгам', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55260', 'Расходы по гарантийному обслуживанию', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55270', 'Расходы по износу и амортизации', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55280', 'Расходы на премиальные вознаграждения', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55290', 'Прочие реализационные расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55300', 'Общие и административные расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE/PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55310', 'Расходы на оплату труда', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55311', 'Расходы по отчислениям в социальные фонды', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55312', 'Расходы по аренде', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55313', 'Расходы по оплате профессиональных услуг', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55314', 'Налоги и сборы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55315', 'Расходы офисных принадлежностей', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55316', 'Ремонт и техобслуживание основных средств', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55317', 'Расходы по компьютерному обеспечению', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55318', 'Командировочные расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55319', 'Штрафы, пени, неустойки', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55320', 'Расходы на исследования и научные разработки', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55321', 'Расходы на износ основных средств', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55322', 'Расходы по амортизации нематериальных активов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55323', 'Расходы по аудиту', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55324', 'Расходы по НДС, не принимаемому к зачету', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55325', 'Коммунальные расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55326', 'Коммуникационные расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55327', 'Расходы электроэнергии', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55328', 'Расходы топлива', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55329', 'Представительские расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55330', 'Расходы на благотворительные цели', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '55350', 'Прочие общие и административные расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66000', 'Доходы от неоперационной деятельности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66010', 'Доходы в виде процентов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66020', 'Доходы от инвестиций', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66030', 'Доходы от дивидендов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66040', 'Доходы от курсовых разниц', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66050', 'Доходы от конвертации', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66060', 'Доходы от выбытия долгосрочных активов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66070', 'Прочие неоперационные расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66100', 'Расходы от неоперационной деятельности', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66110', 'Расходы в виде процентов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66120', 'Убытки от инвестиции', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66130', 'Убытки от обесценения', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66140', 'Убытки от курсовых разниц', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66150', 'Убытки от конвертации', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66160', 'Убытки от выбытия долгосрочных активов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66170', 'Прочие неоперационные расходы', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '66200', 'Расходы(доходы) по налогу на прибыль', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'ACTIVE') );
INSERT INTO "OrmasSchema".chart_of_accounts(
            chart_of_account_id, number_of_account, name_of_account, account_type_id)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), '70000', 'Свод доходов и расходов', (SELECT account_type_id from "OrmasSchema".account_type 
																				WHERE account_type_name = 'PASSIVE') );
