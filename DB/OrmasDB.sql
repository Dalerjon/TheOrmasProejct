--
-- PostgreSQL database dump
--

-- Dumped from database version 9.5.4
-- Dumped by pg_dump version 9.5.4

-- Started on 2018-07-03 12:06:30

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 7 (class 2615 OID 352179)
-- Name: OrmasSchema; Type: SCHEMA; Schema: -; Owner: postgres
--

CREATE SCHEMA "OrmasSchema";


ALTER SCHEMA "OrmasSchema" OWNER TO postgres;

--
-- TOC entry 3030 (class 0 OID 0)
-- Dependencies: 7
-- Name: SCHEMA "OrmasSchema"; Type: COMMENT; Schema: -; Owner: postgres
--

COMMENT ON SCHEMA "OrmasSchema" IS 'Ormas application schema';


--
-- TOC entry 1 (class 3079 OID 12355)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 3034 (class 0 OID 0)
-- Dependencies: 1
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = "OrmasSchema", pg_catalog;

--
-- TOC entry 182 (class 1259 OID 352180)
-- Name: acc_seq; Type: SEQUENCE; Schema: OrmasSchema; Owner: postgres
--

CREATE SEQUENCE acc_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 999999999
    CACHE 1;


ALTER TABLE acc_seq OWNER TO postgres;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 183 (class 1259 OID 352182)
-- Name: access_items; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE access_items (
    access_item_id integer NOT NULL,
    access_item_eng character varying(30) NOT NULL,
    access_item_ru character varying(30) NOT NULL,
    access_division character varying(20) NOT NULL
);


ALTER TABLE access_items OWNER TO postgres;

--
-- TOC entry 184 (class 1259 OID 352185)
-- Name: access_items_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW access_items_view AS
 SELECT access_items.access_item_id,
    access_items.access_item_eng,
    access_items.access_item_ru AS access_iterm_ru,
    access_items.access_division
   FROM access_items;


ALTER TABLE access_items_view OWNER TO postgres;

--
-- TOC entry 185 (class 1259 OID 352189)
-- Name: accesses; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE accesses (
    access_id integer NOT NULL,
    role_id integer NOT NULL,
    access_item_id integer NOT NULL
);


ALTER TABLE accesses OWNER TO postgres;

--
-- TOC entry 186 (class 1259 OID 352192)
-- Name: roles; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE roles (
    role_id integer NOT NULL,
    role_code character varying(20) NOT NULL,
    role_name character varying(50) NOT NULL,
    comment character varying(100)
);


ALTER TABLE roles OWNER TO postgres;

--
-- TOC entry 187 (class 1259 OID 352195)
-- Name: accesses_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW accesses_view AS
 SELECT accesses.access_id,
    r.role_name,
    a.access_item_eng,
    a.access_item_ru,
    a.access_division,
    accesses.role_id,
    accesses.access_item_id
   FROM ((accesses
     JOIN roles r ON ((r.role_id = accesses.role_id)))
     JOIN access_items a ON ((a.access_item_id = accesses.access_item_id)));


ALTER TABLE accesses_view OWNER TO postgres;

--
-- TOC entry 188 (class 1259 OID 352199)
-- Name: account_history; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE account_history (
    account_history_id integer NOT NULL,
    account_id integer NOT NULL,
    account_number character varying(20) NOT NULL,
    start_balance numeric(20,3) NOT NULL,
    current_balance numeric(20,3) NOT NULL,
    from_date date,
    till_date date
);


ALTER TABLE account_history OWNER TO postgres;

--
-- TOC entry 189 (class 1259 OID 352202)
-- Name: account_history_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW account_history_view AS
 SELECT account_history.account_history_id,
    account_history.account_id,
    account_history.account_number,
    account_history.start_balance,
    account_history.current_balance,
    account_history.from_date,
    account_history.till_date
   FROM account_history;


ALTER TABLE account_history_view OWNER TO postgres;

--
-- TOC entry 190 (class 1259 OID 352206)
-- Name: account_type; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE account_type (
    account_type_id integer NOT NULL,
    account_type_name character varying(50) NOT NULL,
    account_type_number integer NOT NULL,
    comment character varying(100)
);


ALTER TABLE account_type OWNER TO postgres;

--
-- TOC entry 191 (class 1259 OID 352209)
-- Name: account_type_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW account_type_view AS
 SELECT account_type.account_type_id,
    account_type.account_type_name,
    account_type.account_type_number,
    account_type.comment
   FROM account_type;


ALTER TABLE account_type_view OWNER TO postgres;

--
-- TOC entry 192 (class 1259 OID 352213)
-- Name: accounts; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE accounts (
    account_id integer NOT NULL,
    account_number character varying(20) NOT NULL,
    start_balance numeric(20,3) NOT NULL,
    current_balance numeric(20,3) NOT NULL
);


ALTER TABLE accounts OWNER TO postgres;

--
-- TOC entry 193 (class 1259 OID 352216)
-- Name: accounts_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW accounts_view AS
 SELECT accounts.account_id,
    accounts.account_number,
    accounts.start_balance,
    accounts.current_balance
   FROM accounts;


ALTER TABLE accounts_view OWNER TO postgres;

--
-- TOC entry 194 (class 1259 OID 352220)
-- Name: balance_payment; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE balance_payment (
    balance_id integer NOT NULL,
    payment_id integer NOT NULL
);


ALTER TABLE balance_payment OWNER TO postgres;

--
-- TOC entry 195 (class 1259 OID 352223)
-- Name: balance_payment_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW balance_payment_view AS
 SELECT balance_payment.balance_id,
    balance_payment.payment_id
   FROM balance_payment;


ALTER TABLE balance_payment_view OWNER TO postgres;

--
-- TOC entry 196 (class 1259 OID 352227)
-- Name: balance_payslip; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE balance_payslip (
    balance_id integer NOT NULL,
    payslip_id integer NOT NULL
);


ALTER TABLE balance_payslip OWNER TO postgres;

--
-- TOC entry 197 (class 1259 OID 352230)
-- Name: balance_payslip_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW balance_payslip_view AS
 SELECT balance_payslip.balance_id,
    balance_payslip.payslip_id
   FROM balance_payslip;


ALTER TABLE balance_payslip_view OWNER TO postgres;

--
-- TOC entry 198 (class 1259 OID 352234)
-- Name: balance_refund; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE balance_refund (
    balance_id integer NOT NULL,
    refund_id integer NOT NULL
);


ALTER TABLE balance_refund OWNER TO postgres;

--
-- TOC entry 199 (class 1259 OID 352237)
-- Name: balance_refund_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW balance_refund_view AS
 SELECT balance_refund.balance_id,
    balance_refund.refund_id
   FROM balance_refund;


ALTER TABLE balance_refund_view OWNER TO postgres;

--
-- TOC entry 200 (class 1259 OID 352241)
-- Name: balance_withdrawal; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE balance_withdrawal (
    balance_id integer NOT NULL,
    withdrawal_id integer NOT NULL
);


ALTER TABLE balance_withdrawal OWNER TO postgres;

--
-- TOC entry 201 (class 1259 OID 352244)
-- Name: balance_withdrawal_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW balance_withdrawal_view AS
 SELECT balance_withdrawal.balance_id,
    balance_withdrawal.withdrawal_id
   FROM balance_withdrawal;


ALTER TABLE balance_withdrawal_view OWNER TO postgres;

--
-- TOC entry 202 (class 1259 OID 352248)
-- Name: balances; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE balances (
    balance_id integer NOT NULL,
    user_id integer NOT NULL,
    subaccount_id integer NOT NULL
);


ALTER TABLE balances OWNER TO postgres;

--
-- TOC entry 203 (class 1259 OID 352251)
-- Name: currencies; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE currencies (
    currency_id integer NOT NULL,
    currency_code integer,
    currency_short_name character varying(3),
    currency_name character varying(20),
    currency_unit integer NOT NULL,
    currency_main_trade boolean
);


ALTER TABLE currencies OWNER TO postgres;

--
-- TOC entry 204 (class 1259 OID 352254)
-- Name: subaccounts; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE subaccounts (
    subaccount_id integer NOT NULL,
    account_id integer NOT NULL,
    subaccount_number character varying(20) NOT NULL,
    start_balance numeric(20,3) NOT NULL,
    current_balance numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    status_id integer NOT NULL,
    date_opened date NOT NULL,
    date_closed date,
    details character varying(100)
);


ALTER TABLE subaccounts OWNER TO postgres;

--
-- TOC entry 205 (class 1259 OID 352257)
-- Name: users; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE users (
    user_id integer NOT NULL,
    user_email character varying(30) NOT NULL,
    user_name character varying(40) NOT NULL,
    user_surname character varying(50),
    user_phone character varying(20),
    user_address character varying(50),
    role_id integer NOT NULL,
    password character varying(30),
    activated boolean
);


ALTER TABLE users OWNER TO postgres;

--
-- TOC entry 206 (class 1259 OID 352260)
-- Name: balances_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW balances_view AS
 SELECT balances.balance_id,
    u.user_name,
    u.user_surname,
    s.current_balance,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = s.currency_id)) AS currency_name,
    balances.user_id,
    balances.subaccount_id
   FROM ((balances
     JOIN users u ON ((u.user_id = balances.user_id)))
     JOIN subaccounts s ON ((s.subaccount_id = balances.subaccount_id)));


ALTER TABLE balances_view OWNER TO postgres;

--
-- TOC entry 207 (class 1259 OID 352265)
-- Name: chart_of_accounts; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE chart_of_accounts (
    chart_of_account_id integer NOT NULL,
    number_of_account character varying(5) NOT NULL,
    name_of_account character varying(150) NOT NULL,
    account_type_id integer
);


ALTER TABLE chart_of_accounts OWNER TO postgres;

--
-- TOC entry 208 (class 1259 OID 352268)
-- Name: chart_of_accounts_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW chart_of_accounts_view AS
 SELECT chart_of_accounts.chart_of_account_id,
    chart_of_accounts.number_of_account,
    chart_of_accounts.name_of_account,
    at.account_type_name,
    chart_of_accounts.account_type_id
   FROM (chart_of_accounts
     JOIN account_type at ON ((at.account_type_id = chart_of_accounts.account_type_id)));


ALTER TABLE chart_of_accounts_view OWNER TO postgres;

--
-- TOC entry 209 (class 1259 OID 352272)
-- Name: clients; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE clients (
    user_id integer NOT NULL,
    firm character varying(50) NOT NULL,
    firm_number character varying(10),
    location_id integer NOT NULL
);


ALTER TABLE clients OWNER TO postgres;

--
-- TOC entry 210 (class 1259 OID 352275)
-- Name: locations; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE locations (
    location_id integer NOT NULL,
    country_name character varying(30) NOT NULL,
    country_code character varying(4) NOT NULL,
    region_name character varying(30) NOT NULL,
    city_name character varying(30) NOT NULL
);


ALTER TABLE locations OWNER TO postgres;

--
-- TOC entry 211 (class 1259 OID 352278)
-- Name: clients_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW clients_view AS
 SELECT users.user_id,
    users.user_name,
    users.user_surname,
    users.user_phone,
    ( SELECT locations.country_name
           FROM locations
          WHERE (locations.location_id = clients.location_id)) AS country_name,
    ( SELECT locations.region_name
           FROM locations
          WHERE (locations.location_id = clients.location_id)) AS region_name,
    ( SELECT locations.city_name
           FROM locations
          WHERE (locations.location_id = clients.location_id)) AS city_name,
    users.user_address,
    clients.firm,
    clients.firm_number,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = users.role_id)) AS role_name,
    users.password,
    users.user_email,
    users.activated,
    users.role_id,
    clients.location_id
   FROM (clients
     JOIN users ON ((users.user_id = clients.user_id)));


ALTER TABLE clients_view OWNER TO postgres;

--
-- TOC entry 212 (class 1259 OID 352283)
-- Name: companies; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE companies (
    company_id integer NOT NULL,
    company_name character varying(60) NOT NULL,
    company_address character varying(60) NOT NULL,
    company_phone character varying(15) NOT NULL,
    comment character varying(100)
);


ALTER TABLE companies OWNER TO postgres;

--
-- TOC entry 213 (class 1259 OID 352286)
-- Name: companies_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW companies_view AS
 SELECT companies.company_id,
    companies.company_name,
    companies.company_address,
    companies.company_phone,
    companies.comment
   FROM companies;


ALTER TABLE companies_view OWNER TO postgres;

--
-- TOC entry 214 (class 1259 OID 352290)
-- Name: company_account; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE company_account (
    company_account_id integer NOT NULL,
    company_id integer NOT NULL,
    account_id integer NOT NULL
);


ALTER TABLE company_account OWNER TO postgres;

--
-- TOC entry 215 (class 1259 OID 352293)
-- Name: company_account_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW company_account_view AS
 SELECT company_account.company_account_id,
    c.company_name,
    a.account_number,
    company_account.company_id,
    company_account.account_id
   FROM ((company_account
     JOIN companies c ON ((c.company_id = company_account.company_id)))
     JOIN accounts a ON ((a.account_id = company_account.account_id)));


ALTER TABLE company_account_view OWNER TO postgres;

--
-- TOC entry 216 (class 1259 OID 352297)
-- Name: company_employee; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE company_employee (
    company_employee_id integer NOT NULL,
    company_id integer NOT NULL,
    employee_id integer NOT NULL
);


ALTER TABLE company_employee OWNER TO postgres;

--
-- TOC entry 217 (class 1259 OID 352300)
-- Name: company_employee_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW company_employee_view AS
 SELECT company_employee.company_employee_id,
    c.company_name,
    e.user_name,
    e.user_surname,
    e.user_phone,
    company_employee.company_id,
    company_employee.employee_id
   FROM ((company_employee
     JOIN companies c ON ((c.company_id = company_employee.company_id)))
     JOIN users e ON ((e.user_id = company_employee.employee_id)));


ALTER TABLE company_employee_view OWNER TO postgres;

--
-- TOC entry 218 (class 1259 OID 352304)
-- Name: consume_product_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE consume_product_list (
    consume_product_list_id integer NOT NULL,
    consume_product_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(20,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE consume_product_list OWNER TO postgres;

--
-- TOC entry 219 (class 1259 OID 352307)
-- Name: measures; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE measures (
    measure_id integer NOT NULL,
    measure_name character varying(15) NOT NULL,
    measure_short_name character varying(4) NOT NULL,
    measure_unit integer
);


ALTER TABLE measures OWNER TO postgres;

--
-- TOC entry 220 (class 1259 OID 352310)
-- Name: products; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE products (
    product_id integer NOT NULL,
    company_id integer NOT NULL,
    product_name character varying(50) NOT NULL,
    volume numeric(20,5) NOT NULL,
    measure_id integer NOT NULL,
    price numeric(20,5) NOT NULL,
    product_type_id integer NOT NULL,
    shelf_life integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE products OWNER TO postgres;

--
-- TOC entry 221 (class 1259 OID 352313)
-- Name: status; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE status (
    status_id integer NOT NULL,
    status_code character varying(4),
    status_name character varying(15),
    comment character varying(100)
);


ALTER TABLE status OWNER TO postgres;

--
-- TOC entry 3035 (class 0 OID 0)
-- Dependencies: 221
-- Name: COLUMN status.status_id; Type: COMMENT; Schema: OrmasSchema; Owner: postgres
--

COMMENT ON COLUMN status.status_id IS '
';


--
-- TOC entry 222 (class 1259 OID 352316)
-- Name: consume_product_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW consume_product_list_view AS
 SELECT consume_product_list.consume_product_list_id,
    consume_product_list.consume_product_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    consume_product_list.count,
    consume_product_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = consume_product_list.currency_id)) AS sum_currency_name,
    s.status_name,
    consume_product_list.product_id,
    consume_product_list.status_id,
    consume_product_list.currency_id
   FROM ((consume_product_list
     JOIN products p ON ((p.product_id = consume_product_list.product_id)))
     JOIN status s ON ((s.status_id = consume_product_list.status_id)));


ALTER TABLE consume_product_list_view OWNER TO postgres;

--
-- TOC entry 223 (class 1259 OID 352321)
-- Name: consume_products; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE consume_products (
    consume_product_id integer NOT NULL,
    user_id integer NOT NULL,
    consume_product_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE consume_products OWNER TO postgres;

--
-- TOC entry 224 (class 1259 OID 352324)
-- Name: employees; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE employees (
    user_id integer NOT NULL,
    position_id integer NOT NULL,
    birth_date date NOT NULL,
    hire_date date NOT NULL
);


ALTER TABLE employees OWNER TO postgres;

--
-- TOC entry 225 (class 1259 OID 352327)
-- Name: positions; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE positions (
    position_id integer NOT NULL,
    position_name character varying(50) NOT NULL
);


ALTER TABLE positions OWNER TO postgres;

--
-- TOC entry 226 (class 1259 OID 352330)
-- Name: consume_products_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW consume_products_view AS
 SELECT consume_products.consume_product_id,
    to_char(consume_products.consume_product_date, 'dd.MM.yyyy hh24:mm'::text) AS consume_product_date,
    to_char(consume_products.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    consume_products.count,
    consume_products.sum,
    c.currency_short_name AS currency_name,
    consume_products.employee_id,
    consume_products.user_id,
    consume_products.status_id,
    consume_products.currency_id
   FROM ((((consume_products
     JOIN users u1 ON ((u1.user_id = consume_products.user_id)))
     JOIN users u2 ON ((u2.user_id = consume_products.employee_id)))
     JOIN status s ON ((s.status_id = consume_products.status_id)))
     JOIN currencies c ON ((c.currency_id = consume_products.currency_id)));


ALTER TABLE consume_products_view OWNER TO postgres;

--
-- TOC entry 227 (class 1259 OID 352335)
-- Name: consume_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE consume_raw_list (
    consume_raw_list_id integer NOT NULL,
    consume_raw_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE consume_raw_list OWNER TO postgres;

--
-- TOC entry 228 (class 1259 OID 352338)
-- Name: consume_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW consume_raw_list_view AS
 SELECT consume_raw_list.consume_raw_list_id,
    consume_raw_list.consume_raw_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    consume_raw_list.count,
    consume_raw_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = consume_raw_list.currency_id)) AS sum_currency_name,
    s.status_name,
    consume_raw_list.product_id,
    consume_raw_list.status_id,
    consume_raw_list.currency_id
   FROM ((consume_raw_list
     JOIN products p ON ((p.product_id = consume_raw_list.product_id)))
     JOIN status s ON ((s.status_id = consume_raw_list.status_id)));


ALTER TABLE consume_raw_list_view OWNER TO postgres;

--
-- TOC entry 229 (class 1259 OID 352343)
-- Name: consume_raws; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE consume_raws (
    consume_raw_id integer NOT NULL,
    user_id integer NOT NULL,
    consume_raw_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE consume_raws OWNER TO postgres;

--
-- TOC entry 230 (class 1259 OID 352346)
-- Name: consume_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW consume_raws_view AS
 SELECT consume_raws.consume_raw_id,
    to_char(consume_raws.consume_raw_date, 'dd.MM.yyyy hh24:mm'::text) AS consume_raw_date,
    to_char(consume_raws.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    consume_raws.count,
    consume_raws.sum,
    c.currency_short_name AS currency_name,
    consume_raws.employee_id,
    consume_raws.user_id,
    consume_raws.status_id,
    consume_raws.currency_id
   FROM ((((consume_raws
     JOIN users u1 ON ((u1.user_id = consume_raws.user_id)))
     JOIN users u2 ON ((u2.user_id = consume_raws.employee_id)))
     JOIN status s ON ((s.status_id = consume_raws.status_id)))
     JOIN currencies c ON ((c.currency_id = consume_raws.currency_id)));


ALTER TABLE consume_raws_view OWNER TO postgres;

--
-- TOC entry 231 (class 1259 OID 352351)
-- Name: currencies_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW currencies_view AS
 SELECT currencies.currency_id,
    currencies.currency_code,
    currencies.currency_short_name,
    currencies.currency_name,
    currencies.currency_unit,
    currencies.currency_main_trade
   FROM currencies;


ALTER TABLE currencies_view OWNER TO postgres;

--
-- TOC entry 232 (class 1259 OID 352355)
-- Name: employees_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW employees_view AS
 SELECT users.user_id,
    users.user_name,
    users.user_surname,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = employees.position_id)) AS position_name,
    users.user_phone,
    users.user_address,
    to_char((employees.birth_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS birth_date,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = users.role_id)) AS role_name,
    to_char((employees.hire_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS hire_date,
    users.password,
    users.user_email,
    users.activated,
    users.role_id,
    employees.position_id
   FROM (employees
     JOIN users ON ((users.user_id = employees.user_id)));


ALTER TABLE employees_view OWNER TO postgres;

--
-- TOC entry 233 (class 1259 OID 352360)
-- Name: entries; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE entries (
    entry_id integer NOT NULL,
    entry_date timestamp without time zone NOT NULL,
    debiting_account_id integer NOT NULL,
    value numeric(20,3) NOT NULL,
    crediting_account_id integer NOT NULL
);


ALTER TABLE entries OWNER TO postgres;

--
-- TOC entry 234 (class 1259 OID 352363)
-- Name: entries_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW entries_view AS
 SELECT entries.entry_id,
    to_char(entries.entry_date, 'dd.MM.yyyy'::text) AS entry_date,
    da.account_number AS debiting_account_number,
    entries.value,
    ca.account_number AS crediting_account_number,
    entries.debiting_account_id,
    entries.crediting_account_id
   FROM ((entries
     JOIN accounts da ON ((da.account_id = entries.debiting_account_id)))
     JOIN accounts ca ON ((ca.account_id = entries.crediting_account_id)));


ALTER TABLE entries_view OWNER TO postgres;

--
-- TOC entry 235 (class 1259 OID 352367)
-- Name: entry_routing; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE entry_routing (
    entry_routing_id integer NOT NULL,
    operation_name character varying(200) NOT NULL,
    debit integer NOT NULL,
    credit integer NOT NULL
);


ALTER TABLE entry_routing OWNER TO postgres;

--
-- TOC entry 236 (class 1259 OID 352370)
-- Name: entry_routing_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW entry_routing_view AS
 SELECT entry_routing.entry_routing_id,
    entry_routing.operation_name,
    entry_routing.debit,
    entry_routing.credit
   FROM entry_routing;


ALTER TABLE entry_routing_view OWNER TO postgres;

--
-- TOC entry 237 (class 1259 OID 352374)
-- Name: entry_subaccount; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE entry_subaccount (
    entry_id integer NOT NULL,
    subaccount_id integer NOT NULL
);


ALTER TABLE entry_subaccount OWNER TO postgres;

--
-- TOC entry 238 (class 1259 OID 352377)
-- Name: entry_subaccount_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW entry_subaccount_view AS
 SELECT entry_subaccount.entry_id,
    entry_subaccount.subaccount_id
   FROM entry_subaccount;


ALTER TABLE entry_subaccount_view OWNER TO postgres;

--
-- TOC entry 239 (class 1259 OID 352381)
-- Name: financial_report; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE financial_report (
    financial_report_id integer NOT NULL,
    acc_44010 numeric(20,3),
    acc_55010 numeric(20,3),
    acc_552 numeric(20,3),
    acc_55270 numeric(20,3),
    acc_553 numeric(20,3),
    acc_55321 numeric(20,3),
    acc_44020_90 numeric(20,3),
    acc_66010_66110 numeric(20,3),
    acc_66020_66120 numeric(20,3),
    acc_66040_66140 numeric(20,3),
    acc_66050_66150 numeric(20,3),
    acc_66060_66160 numeric(20,3),
    acc_66130 numeric(20,3),
    acc_66070_66170 numeric(20,3),
    tax numeric(20,3),
    from_date date,
    till_date date
);


ALTER TABLE financial_report OWNER TO postgres;

--
-- TOC entry 240 (class 1259 OID 352384)
-- Name: financial_report_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW financial_report_view AS
 SELECT financial_report.financial_report_id,
    financial_report.acc_44010,
    financial_report.acc_55010,
    financial_report.acc_552,
    financial_report.acc_55270,
    financial_report.acc_553,
    financial_report.acc_55321,
    financial_report.acc_44020_90,
    financial_report.acc_66010_66110,
    financial_report.acc_66020_66120,
    financial_report.acc_66040_66140,
    financial_report.acc_66050_66150,
    financial_report.acc_66060_66160,
    financial_report.acc_66130,
    financial_report.acc_66070_66170,
    financial_report.tax,
    financial_report.from_date,
    financial_report.till_date
   FROM financial_report;


ALTER TABLE financial_report_view OWNER TO postgres;

--
-- TOC entry 241 (class 1259 OID 352388)
-- Name: id_seq; Type: SEQUENCE; Schema: OrmasSchema; Owner: postgres
--

CREATE SEQUENCE id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 9999999999
    CACHE 1;


ALTER TABLE id_seq OWNER TO postgres;

--
-- TOC entry 242 (class 1259 OID 352390)
-- Name: inventorization_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE inventorization_list (
    inventorization_list_id integer NOT NULL,
    inventorization_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE inventorization_list OWNER TO postgres;

--
-- TOC entry 243 (class 1259 OID 352393)
-- Name: inventorization_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW inventorization_list_view AS
 SELECT inventorization_list.inventorization_list_id,
    inventorization_list.inventorization_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    inventorization_list.count,
    inventorization_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = inventorization_list.currency_id)) AS sum_currency_name,
    s.status_name,
    inventorization_list.product_id,
    inventorization_list.status_id,
    inventorization_list.currency_id
   FROM ((inventorization_list
     JOIN products p ON ((p.product_id = inventorization_list.product_id)))
     JOIN status s ON ((s.status_id = inventorization_list.status_id)));


ALTER TABLE inventorization_list_view OWNER TO postgres;

--
-- TOC entry 244 (class 1259 OID 352398)
-- Name: inventorizations; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE inventorizations (
    inventorization_id integer NOT NULL,
    user_id integer NOT NULL,
    inventorization_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE inventorizations OWNER TO postgres;

--
-- TOC entry 245 (class 1259 OID 352401)
-- Name: inventorizations_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW inventorizations_view AS
 SELECT inventorizations.inventorization_id,
    to_char(inventorizations.inventorization_date, 'dd.MM.yyyy hh24:mm'::text) AS inventorization_date,
    to_char(inventorizations.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    inventorizations.count,
    inventorizations.sum,
    c.currency_short_name AS currency_name,
    inventorizations.employee_id,
    inventorizations.user_id,
    inventorizations.status_id,
    inventorizations.currency_id
   FROM ((((inventorizations
     JOIN users u1 ON ((u1.user_id = inventorizations.user_id)))
     JOIN users u2 ON ((u2.user_id = inventorizations.employee_id)))
     JOIN status s ON ((s.status_id = inventorizations.status_id)))
     JOIN currencies c ON ((c.currency_id = inventorizations.currency_id)));


ALTER TABLE inventorizations_view OWNER TO postgres;

--
-- TOC entry 246 (class 1259 OID 352406)
-- Name: jobprice; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE jobprice (
    jobprice_id integer NOT NULL,
    product_id integer NOT NULL,
    value numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    volume numeric(20,3) NOT NULL,
    measure_id integer NOT NULL,
    position_id integer NOT NULL
);


ALTER TABLE jobprice OWNER TO postgres;

--
-- TOC entry 247 (class 1259 OID 352409)
-- Name: jobprice_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW jobprice_view AS
 SELECT jobprice.jobprice_id,
    p.product_name,
    jobprice.value,
    c.currency_short_name AS currency_name,
    jobprice.volume,
    m.measure_name,
    pos.position_name,
    jobprice.product_id,
    jobprice.currency_id,
    jobprice.measure_id,
    jobprice.position_id
   FROM ((((jobprice
     JOIN products p ON ((p.product_id = jobprice.product_id)))
     JOIN currencies c ON ((c.currency_id = jobprice.currency_id)))
     JOIN measures m ON ((m.measure_id = jobprice.measure_id)))
     JOIN positions pos ON ((pos.position_id = jobprice.position_id)));


ALTER TABLE jobprice_view OWNER TO postgres;

--
-- TOC entry 248 (class 1259 OID 352414)
-- Name: jobsheet; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE jobsheet (
    jobsheet_id integer NOT NULL,
    jobsheet_date date NOT NULL,
    count numeric(20,3) NOT NULL,
    product_id integer NOT NULL,
    employee_id integer NOT NULL
);


ALTER TABLE jobsheet OWNER TO postgres;

--
-- TOC entry 249 (class 1259 OID 352417)
-- Name: jobsheet_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW jobsheet_view AS
 SELECT jobsheet.jobsheet_id,
    to_char((jobsheet.jobsheet_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS jobsheet_date,
    e.user_name,
    e.user_surname,
    e.user_phone,
    p.product_name,
    jobsheet.count,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    jobsheet.product_id,
    jobsheet.employee_id
   FROM ((jobsheet
     JOIN products p ON ((p.product_id = jobsheet.product_id)))
     JOIN users e ON ((e.user_id = jobsheet.employee_id)));


ALTER TABLE jobsheet_view OWNER TO postgres;

--
-- TOC entry 250 (class 1259 OID 352422)
-- Name: locations_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW locations_view AS
 SELECT locations.location_id,
    locations.country_name,
    locations.country_code,
    locations.region_name,
    locations.city_name
   FROM locations;


ALTER TABLE locations_view OWNER TO postgres;

--
-- TOC entry 251 (class 1259 OID 352426)
-- Name: measures_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW measures_view AS
 SELECT measures.measure_id,
    measures.measure_name,
    measures.measure_short_name,
    measures.measure_unit
   FROM measures;


ALTER TABLE measures_view OWNER TO postgres;

--
-- TOC entry 252 (class 1259 OID 352430)
-- Name: net_cost; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE net_cost (
    net_cost_id integer NOT NULL,
    net_cost_date timestamp without time zone NOT NULL,
    net_cost_value numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    product_id integer NOT NULL,
    is_outdated boolean
);


ALTER TABLE net_cost OWNER TO postgres;

--
-- TOC entry 253 (class 1259 OID 352433)
-- Name: net_cost_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW net_cost_view AS
 SELECT net_cost.net_cost_id,
    to_char(net_cost.net_cost_date, 'dd.MM.yyyy hh24:mm'::text) AS net_cost_date,
    p.product_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    net_cost.net_cost_value,
    c.currency_short_name AS currency_name,
    net_cost.currency_id,
    net_cost.product_id,
    net_cost.is_outdated
   FROM ((net_cost
     JOIN products p ON ((p.product_id = net_cost.product_id)))
     JOIN currencies c ON ((c.currency_id = net_cost.currency_id)));


ALTER TABLE net_cost_view OWNER TO postgres;

--
-- TOC entry 254 (class 1259 OID 352438)
-- Name: order_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE order_list (
    order_list_id integer NOT NULL,
    order_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE order_list OWNER TO postgres;

--
-- TOC entry 255 (class 1259 OID 352441)
-- Name: order_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW order_list_view AS
 SELECT order_list.order_list_id,
    order_list.order_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    order_list.count,
    order_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = order_list.currency_id)) AS sum_currency_name,
    s.status_name,
    order_list.product_id,
    order_list.status_id,
    order_list.currency_id
   FROM ((order_list
     JOIN products p ON ((p.product_id = order_list.product_id)))
     JOIN status s ON ((s.status_id = order_list.status_id)));


ALTER TABLE order_list_view OWNER TO postgres;

--
-- TOC entry 256 (class 1259 OID 352446)
-- Name: order_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE order_raw_list (
    order_raw_list_id integer NOT NULL,
    order_raw_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE order_raw_list OWNER TO postgres;

--
-- TOC entry 257 (class 1259 OID 352449)
-- Name: order_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW order_raw_list_view AS
 SELECT order_raw_list.order_raw_list_id,
    order_raw_list.order_raw_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    order_raw_list.count,
    order_raw_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = order_raw_list.currency_id)) AS sum_currency_name,
    s.status_name,
    order_raw_list.product_id,
    order_raw_list.status_id,
    order_raw_list.currency_id
   FROM ((order_raw_list
     JOIN products p ON ((p.product_id = order_raw_list.product_id)))
     JOIN status s ON ((s.status_id = order_raw_list.status_id)));


ALTER TABLE order_raw_list_view OWNER TO postgres;

--
-- TOC entry 258 (class 1259 OID 352454)
-- Name: order_raws; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE order_raws (
    order_raw_id integer NOT NULL,
    purveyor_id integer NOT NULL,
    order_raw_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE order_raws OWNER TO postgres;

--
-- TOC entry 259 (class 1259 OID 352457)
-- Name: purveyors; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE purveyors (
    user_id integer NOT NULL,
    company_name character varying(100) NOT NULL,
    location_id integer NOT NULL
);


ALTER TABLE purveyors OWNER TO postgres;

--
-- TOC entry 260 (class 1259 OID 352460)
-- Name: order_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW order_raws_view AS
 SELECT order_raws.order_raw_id,
    to_char(order_raws.order_raw_date, 'dd.MM.yyyy hh24:mm'::text) AS order_raw_date,
    to_char(order_raws.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS purveyor_name,
    u1.user_surname AS purveyor_surname,
    u1.user_phone AS purveyor_phone,
    ( SELECT purveyors.company_name
           FROM purveyors
          WHERE (purveyors.user_id = u1.user_id)) AS purveyor_company_name,
    u2.user_name AS employee_name,
    u2.user_surname AS employee_surname,
    u2.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS employee_position_name,
    order_raws.count,
    order_raws.sum,
    c.currency_short_name AS currency_name,
    order_raws.employee_id,
    order_raws.purveyor_id,
    order_raws.status_id,
    order_raws.currency_id
   FROM ((((order_raws
     JOIN users u1 ON ((u1.user_id = order_raws.purveyor_id)))
     JOIN users u2 ON ((u2.user_id = order_raws.employee_id)))
     JOIN status s ON ((s.status_id = order_raws.status_id)))
     JOIN currencies c ON ((c.currency_id = order_raws.currency_id)));


ALTER TABLE order_raws_view OWNER TO postgres;

--
-- TOC entry 261 (class 1259 OID 352465)
-- Name: orders; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE orders (
    order_id integer NOT NULL,
    user_id integer NOT NULL,
    order_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE orders OWNER TO postgres;

--
-- TOC entry 262 (class 1259 OID 352468)
-- Name: orders_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW orders_view AS
 SELECT orders.order_id,
    to_char(orders.order_date, 'dd.MM.yyyy hh24:mm'::text) AS order_date,
    to_char(orders.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS client_name,
    u1.user_surname AS client_surname,
    u1.user_phone AS client_phone,
    u1.user_address AS clinet_address,
    ( SELECT clients.firm
           FROM clients
          WHERE (clients.user_id = u1.user_id)) AS client_firm,
    u2.user_name AS employee_name,
    u2.user_surname AS employee_surname,
    u2.user_phone AS employee_phone,
    orders.count,
    orders.sum,
    c.currency_short_name AS currency_name,
    orders.employee_id,
    orders.user_id,
    orders.status_id,
    orders.currency_id
   FROM ((((orders
     JOIN users u1 ON ((u1.user_id = orders.user_id)))
     JOIN users u2 ON ((u2.user_id = orders.employee_id)))
     JOIN status s ON ((s.status_id = orders.status_id)))
     JOIN currencies c ON ((c.currency_id = orders.currency_id)));


ALTER TABLE orders_view OWNER TO postgres;

--
-- TOC entry 263 (class 1259 OID 352473)
-- Name: payments; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE payments (
    payment_id integer NOT NULL,
    payment_date timestamp without time zone NOT NULL,
    payment_value numeric(20,3) NOT NULL,
    user_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE payments OWNER TO postgres;

--
-- TOC entry 264 (class 1259 OID 352476)
-- Name: payments_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW payments_view AS
 SELECT payments.payment_id,
    to_char(payments.payment_date, 'dd.MM.yyyy hh24:mm'::text) AS payment_date,
    payments.payment_value,
    c.currency_short_name AS currency_name,
    payments.user_id,
    payments.currency_id
   FROM (payments
     JOIN currencies c ON ((c.currency_id = payments.currency_id)));


ALTER TABLE payments_view OWNER TO postgres;

--
-- TOC entry 265 (class 1259 OID 352480)
-- Name: payslip_order; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE payslip_order (
    payslip_id integer NOT NULL,
    order_id integer
);


ALTER TABLE payslip_order OWNER TO postgres;

--
-- TOC entry 266 (class 1259 OID 352483)
-- Name: payslip_order_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW payslip_order_view AS
 SELECT payslip_order.payslip_id,
    payslip_order.order_id
   FROM payslip_order;


ALTER TABLE payslip_order_view OWNER TO postgres;

--
-- TOC entry 267 (class 1259 OID 352487)
-- Name: payslips; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE payslips (
    payslip_id integer NOT NULL,
    payslip_date time without time zone NOT NULL,
    payslip_value numeric(20,3) NOT NULL,
    salary_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE payslips OWNER TO postgres;

--
-- TOC entry 268 (class 1259 OID 352490)
-- Name: payslips_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW payslips_view AS
 SELECT payslips.payslip_id,
    to_char((payslips.payslip_date)::interval, 'dd.MM.yyyy hh24:mm'::text) AS payslip_date,
    payslips.payslip_value,
    c.currency_short_name AS currency_name,
    payslips.salary_id,
    payslips.currency_id
   FROM (payslips
     JOIN currencies c ON ((c.currency_id = payslips.currency_id)));


ALTER TABLE payslips_view OWNER TO postgres;

--
-- TOC entry 269 (class 1259 OID 352494)
-- Name: percent_rate; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE percent_rate (
    percent_rate_id integer NOT NULL,
    value numeric(20,3),
    condition character varying(100),
    position_id integer NOT NULL
);


ALTER TABLE percent_rate OWNER TO postgres;

--
-- TOC entry 270 (class 1259 OID 352497)
-- Name: percent_rate_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW percent_rate_view AS
 SELECT percent_rate.percent_rate_id,
    percent_rate.value,
    percent_rate.condition,
    percent_rate.position_id
   FROM (percent_rate
     JOIN positions p ON ((p.position_id = percent_rate.position_id)));


ALTER TABLE percent_rate_view OWNER TO postgres;

--
-- TOC entry 271 (class 1259 OID 352501)
-- Name: photos; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE photos (
    photo_id integer NOT NULL,
    user_id integer,
    product_id integer,
    photo_source character varying(100)
);


ALTER TABLE photos OWNER TO postgres;

--
-- TOC entry 272 (class 1259 OID 352504)
-- Name: photos_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW photos_view AS
 SELECT photos.photo_id,
    photos.user_id,
    photos.product_id,
    photos.photo_source
   FROM photos;


ALTER TABLE photos_view OWNER TO postgres;

--
-- TOC entry 273 (class 1259 OID 352508)
-- Name: positions_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW positions_view AS
 SELECT positions.position_id,
    positions.position_name
   FROM positions;


ALTER TABLE positions_view OWNER TO postgres;

--
-- TOC entry 274 (class 1259 OID 352512)
-- Name: prices; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE prices (
    price_id integer NOT NULL,
    price_date timestamp without time zone NOT NULL,
    price_value numeric(20,5) NOT NULL,
    currency_id integer NOT NULL,
    product_id integer NOT NULL,
    is_outdated boolean
);


ALTER TABLE prices OWNER TO postgres;

--
-- TOC entry 275 (class 1259 OID 352515)
-- Name: prices_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW prices_view AS
 SELECT prices.price_id,
    to_char(prices.price_date, 'dd.MM.yyyy hh24:mm'::text) AS price_date,
    p.product_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    prices.price_value,
    c.currency_short_name AS currency_name,
    prices.currency_id,
    prices.product_id,
    prices.is_outdated
   FROM ((prices
     JOIN products p ON ((p.product_id = prices.product_id)))
     JOIN currencies c ON ((c.currency_id = prices.currency_id)));


ALTER TABLE prices_view OWNER TO postgres;

--
-- TOC entry 276 (class 1259 OID 352520)
-- Name: product_type; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE product_type (
    product_type_id integer NOT NULL,
    product_type_name character varying(50) NOT NULL,
    product_type_short_name character varying(10) NOT NULL,
    product_type_code character varying(15)
);


ALTER TABLE product_type OWNER TO postgres;

--
-- TOC entry 277 (class 1259 OID 352523)
-- Name: product_types_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW product_types_view AS
 SELECT product_type.product_type_id,
    product_type.product_type_name,
    product_type.product_type_short_name,
    product_type.product_type_code
   FROM product_type;


ALTER TABLE product_types_view OWNER TO postgres;

--
-- TOC entry 278 (class 1259 OID 352527)
-- Name: production; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production (
    production_id integer NOT NULL,
    production_date date NOT NULL,
    expiry_date date,
    session_start time without time zone NOT NULL,
    session_end time without time zone
);


ALTER TABLE production OWNER TO postgres;

--
-- TOC entry 279 (class 1259 OID 352530)
-- Name: production_consume_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production_consume_raw_list (
    consume_raw_list_id integer NOT NULL,
    consume_raw_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE production_consume_raw_list OWNER TO postgres;

--
-- TOC entry 280 (class 1259 OID 352533)
-- Name: production_consume_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_consume_raw_list_view AS
 SELECT production_consume_raw_list.consume_raw_list_id,
    production_consume_raw_list.consume_raw_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    production_consume_raw_list.count,
    production_consume_raw_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = production_consume_raw_list.currency_id)) AS sum_currency_name,
    s.status_name,
    production_consume_raw_list.product_id,
    production_consume_raw_list.status_id,
    production_consume_raw_list.currency_id
   FROM ((production_consume_raw_list
     JOIN products p ON ((p.product_id = production_consume_raw_list.product_id)))
     JOIN status s ON ((s.status_id = production_consume_raw_list.status_id)));


ALTER TABLE production_consume_raw_list_view OWNER TO postgres;

--
-- TOC entry 281 (class 1259 OID 352538)
-- Name: production_consume_raws; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production_consume_raws (
    consume_raw_id integer NOT NULL,
    user_id integer,
    consume_raw_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE production_consume_raws OWNER TO postgres;

--
-- TOC entry 282 (class 1259 OID 352541)
-- Name: production_consume_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_consume_raws_view AS
 SELECT production_consume_raws.consume_raw_id,
    to_char(production_consume_raws.consume_raw_date, 'dd.MM.yyyy hh24:mm'::text) AS consume_raw_date,
    to_char(production_consume_raws.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    production_consume_raws.count,
    production_consume_raws.sum,
    c.currency_short_name AS currency_name,
    production_consume_raws.employee_id,
    production_consume_raws.user_id,
    production_consume_raws.status_id,
    production_consume_raws.currency_id
   FROM ((((production_consume_raws
     LEFT JOIN users u1 ON ((u1.user_id = production_consume_raws.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = production_consume_raws.employee_id)))
     JOIN status s ON ((s.status_id = production_consume_raws.status_id)))
     JOIN currencies c ON ((c.currency_id = production_consume_raws.currency_id)));


ALTER TABLE production_consume_raws_view OWNER TO postgres;

--
-- TOC entry 283 (class 1259 OID 352546)
-- Name: production_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production_list (
    production_list_id integer NOT NULL,
    production_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE production_list OWNER TO postgres;

--
-- TOC entry 284 (class 1259 OID 352549)
-- Name: production_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_list_view AS
 SELECT production_list.production_list_id,
    production_list.production_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    production_list.count,
    production_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = production_list.currency_id)) AS sum_currency_name,
    s.status_name,
    production_list.product_id,
    production_list.status_id,
    production_list.currency_id
   FROM ((production_list
     JOIN products p ON ((p.product_id = production_list.product_id)))
     JOIN status s ON ((s.status_id = production_list.status_id)));


ALTER TABLE production_list_view OWNER TO postgres;

--
-- TOC entry 285 (class 1259 OID 352554)
-- Name: production_plan; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production_plan (
    production_plan_id integer NOT NULL,
    production_plan_date timestamp without time zone NOT NULL,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE production_plan OWNER TO postgres;

--
-- TOC entry 286 (class 1259 OID 352557)
-- Name: production_plan_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production_plan_list (
    production_plan_list_id integer NOT NULL,
    production_plan_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE production_plan_list OWNER TO postgres;

--
-- TOC entry 287 (class 1259 OID 352560)
-- Name: production_plan_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_plan_list_view AS
 SELECT production_plan_list.production_plan_list_id,
    production_plan_list.production_plan_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    production_plan_list.count,
    production_plan_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = production_plan_list.currency_id)) AS sum_currency_name,
    s.status_name,
    production_plan_list.product_id,
    production_plan_list.status_id,
    production_plan_list.currency_id
   FROM ((production_plan_list
     JOIN products p ON ((p.product_id = production_plan_list.product_id)))
     JOIN status s ON ((s.status_id = production_plan_list.status_id)));


ALTER TABLE production_plan_list_view OWNER TO postgres;

--
-- TOC entry 288 (class 1259 OID 352565)
-- Name: production_plan_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_plan_view AS
 SELECT production_plan.production_plan_id,
    to_char(production_plan.production_plan_date, 'dd.MM.yyyy hh24:mm'::text) AS production_plan_date,
    production_plan.count,
    production_plan.sum,
    c.currency_short_name AS currency_name,
    s.status_name,
    e.user_name,
    e.user_surname,
    e.user_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = e.position_id)) AS position_name,
    production_plan.employee_id,
    production_plan.status_id,
    production_plan.currency_id
   FROM (((production_plan
     JOIN employees_view e ON ((e.user_id = production_plan.employee_id)))
     JOIN currencies c ON ((c.currency_id = production_plan.currency_id)))
     JOIN status s ON ((s.status_id = production_plan.status_id)));


ALTER TABLE production_plan_view OWNER TO postgres;

--
-- TOC entry 289 (class 1259 OID 352570)
-- Name: production_stock; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE production_stock (
    production_stock_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE production_stock OWNER TO postgres;

--
-- TOC entry 290 (class 1259 OID 352573)
-- Name: production_stock_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_stock_view AS
 SELECT production_stock.production_stock_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    production_stock.count,
    production_stock.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = production_stock.currency_id)) AS sum_currency_name,
    s.status_name,
    production_stock.product_id,
    production_stock.status_id,
    production_stock.currency_id
   FROM ((production_stock
     JOIN products p ON ((p.product_id = production_stock.product_id)))
     JOIN status s ON ((s.status_id = production_stock.status_id)));


ALTER TABLE production_stock_view OWNER TO postgres;

--
-- TOC entry 291 (class 1259 OID 352578)
-- Name: production_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW production_view AS
 SELECT production.production_id,
    to_char((production.production_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS production_date,
    to_char((production.expiry_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS expiry_date,
    to_char(('2001-09-28'::date + (production.session_start)::time with time zone), 'hh24:mm'::text) AS session_start,
    to_char(('2001-09-28'::date + (production.session_end)::time with time zone), 'hh24:mm'::text) AS session_end
   FROM production;


ALTER TABLE production_view OWNER TO postgres;

--
-- TOC entry 292 (class 1259 OID 352582)
-- Name: products_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW products_view AS
 SELECT products.product_id,
    products.product_name,
    products.price,
    cur.currency_short_name AS currency,
    products.volume,
    m.measure_short_name AS measure_name,
    p.product_type_short_name AS product_type_name,
    products.shelf_life,
    c.company_name,
    products.company_id,
    products.measure_id,
    products.product_type_id,
    products.currency_id
   FROM ((((products
     JOIN companies c ON ((c.company_id = products.company_id)))
     JOIN measures m ON ((m.measure_id = products.measure_id)))
     JOIN product_type p ON ((p.product_type_id = products.product_type_id)))
     JOIN currencies cur ON ((cur.currency_id = products.currency_id)));


ALTER TABLE products_view OWNER TO postgres;

--
-- TOC entry 293 (class 1259 OID 352587)
-- Name: purveyors_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW purveyors_view AS
 SELECT users.user_id,
    users.user_name,
    users.user_surname,
    users.user_phone,
    ( SELECT locations.country_name
           FROM locations
          WHERE (locations.location_id = purveyors.location_id)) AS country_name,
    ( SELECT locations.region_name
           FROM locations
          WHERE (locations.location_id = purveyors.location_id)) AS region_name,
    ( SELECT locations.city_name
           FROM locations
          WHERE (locations.location_id = purveyors.location_id)) AS city_name,
    users.user_address,
    purveyors.company_name,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = users.role_id)) AS role_name,
    users.password,
    users.user_email,
    users.activated,
    users.role_id,
    purveyors.location_id
   FROM (purveyors
     JOIN users ON ((users.user_id = purveyors.user_id)));


ALTER TABLE purveyors_view OWNER TO postgres;

--
-- TOC entry 294 (class 1259 OID 352592)
-- Name: receipt_product_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE receipt_product_list (
    receipt_product_list_id integer NOT NULL,
    receipt_product_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE receipt_product_list OWNER TO postgres;

--
-- TOC entry 295 (class 1259 OID 352595)
-- Name: receipt_product_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW receipt_product_list_view AS
 SELECT receipt_product_list.receipt_product_list_id,
    receipt_product_list.receipt_product_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    receipt_product_list.count,
    receipt_product_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = receipt_product_list.currency_id)) AS sum_currency_name,
    s.status_name,
    receipt_product_list.product_id,
    receipt_product_list.status_id,
    receipt_product_list.currency_id
   FROM ((receipt_product_list
     JOIN products p ON ((p.product_id = receipt_product_list.product_id)))
     JOIN status s ON ((s.status_id = receipt_product_list.status_id)));


ALTER TABLE receipt_product_list_view OWNER TO postgres;

--
-- TOC entry 296 (class 1259 OID 352600)
-- Name: receipt_products; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE receipt_products (
    receipt_product_id integer NOT NULL,
    user_id integer NOT NULL,
    receipt_product_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE receipt_products OWNER TO postgres;

--
-- TOC entry 297 (class 1259 OID 352603)
-- Name: receipt_products_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW receipt_products_view AS
 SELECT receipt_products.receipt_product_id,
    to_char(receipt_products.receipt_product_date, 'dd.MM.yyyy hh24:mm'::text) AS receipt_product_date,
    to_char(receipt_products.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    receipt_products.count,
    receipt_products.sum,
    c.currency_short_name AS currency_name,
    receipt_products.employee_id,
    receipt_products.user_id,
    receipt_products.status_id,
    receipt_products.currency_id
   FROM ((((receipt_products
     JOIN users u1 ON ((u1.user_id = receipt_products.user_id)))
     JOIN users u2 ON ((u2.user_id = receipt_products.employee_id)))
     JOIN status s ON ((s.status_id = receipt_products.status_id)))
     JOIN currencies c ON ((c.currency_id = receipt_products.currency_id)));


ALTER TABLE receipt_products_view OWNER TO postgres;

--
-- TOC entry 298 (class 1259 OID 352608)
-- Name: receipt_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE receipt_raw_list (
    receipt_raw_list_id integer NOT NULL,
    receipt_raw_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE receipt_raw_list OWNER TO postgres;

--
-- TOC entry 299 (class 1259 OID 352611)
-- Name: receipt_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW receipt_raw_list_view AS
 SELECT receipt_raw_list.receipt_raw_list_id,
    receipt_raw_list.receipt_raw_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    receipt_raw_list.count,
    receipt_raw_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = receipt_raw_list.currency_id)) AS sum_currency_name,
    s.status_name,
    receipt_raw_list.product_id,
    receipt_raw_list.status_id,
    receipt_raw_list.currency_id
   FROM ((receipt_raw_list
     JOIN products p ON ((p.product_id = receipt_raw_list.product_id)))
     JOIN status s ON ((s.status_id = receipt_raw_list.status_id)));


ALTER TABLE receipt_raw_list_view OWNER TO postgres;

--
-- TOC entry 300 (class 1259 OID 352616)
-- Name: receipt_raws; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE receipt_raws (
    receipt_raw_id integer NOT NULL,
    user_id integer NOT NULL,
    receipt_raw_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE receipt_raws OWNER TO postgres;

--
-- TOC entry 301 (class 1259 OID 352619)
-- Name: receipt_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW receipt_raws_view AS
 SELECT receipt_raws.receipt_raw_id,
    to_char(receipt_raws.receipt_raw_date, 'dd.MM.yyyy hh24:mm'::text) AS receipt_raw_date,
    to_char(receipt_raws.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    receipt_raws.count,
    receipt_raws.sum,
    c.currency_short_name AS currency_name,
    receipt_raws.employee_id,
    receipt_raws.user_id,
    receipt_raws.status_id,
    receipt_raws.currency_id
   FROM ((((receipt_raws
     JOIN users u1 ON ((u1.user_id = receipt_raws.user_id)))
     JOIN users u2 ON ((u2.user_id = receipt_raws.employee_id)))
     JOIN status s ON ((s.status_id = receipt_raws.status_id)))
     JOIN currencies c ON ((c.currency_id = receipt_raws.currency_id)));


ALTER TABLE receipt_raws_view OWNER TO postgres;

--
-- TOC entry 302 (class 1259 OID 352624)
-- Name: refunds; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE refunds (
    refund_id integer NOT NULL,
    refund_date timestamp without time zone NOT NULL,
    refund_value numeric(20,3) NOT NULL,
    user_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE refunds OWNER TO postgres;

--
-- TOC entry 303 (class 1259 OID 352627)
-- Name: refunds_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW refunds_view AS
 SELECT refunds.refund_id,
    to_char(refunds.refund_date, 'dd.MM.yyyy hh24:mm'::text) AS refund_date,
    refunds.refund_value,
    c.currency_short_name AS currency_name,
    refunds.user_id,
    refunds.currency_id
   FROM (refunds
     JOIN currencies c ON ((c.currency_id = refunds.currency_id)));


ALTER TABLE refunds_view OWNER TO postgres;

--
-- TOC entry 304 (class 1259 OID 352631)
-- Name: relation_type; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE relation_type (
    relation_type_id integer NOT NULL,
    relation_name character varying(30) NOT NULL,
    comment character varying(100)
);


ALTER TABLE relation_type OWNER TO postgres;

--
-- TOC entry 305 (class 1259 OID 352634)
-- Name: relation_type_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW relation_type_view AS
 SELECT relation_type.relation_type_id,
    relation_type.relation_name,
    relation_type.comment
   FROM relation_type;


ALTER TABLE relation_type_view OWNER TO postgres;

--
-- TOC entry 306 (class 1259 OID 352638)
-- Name: relations; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE relations (
    relation_id integer NOT NULL,
    user_id_1 integer NOT NULL,
    user_id_2 integer NOT NULL,
    relation_type_id integer NOT NULL
);


ALTER TABLE relations OWNER TO postgres;

--
-- TOC entry 307 (class 1259 OID 352641)
-- Name: relations_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW relations_view AS
 SELECT relations.relation_id,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    rt.relation_name,
    u2.user_name,
    u2.user_surname,
    u2.user_phone,
    relations.user_id_1,
    relations.user_id_2,
    relations.relation_type_id
   FROM (((relations
     JOIN users u1 ON ((u1.user_id = relations.user_id_1)))
     JOIN users u2 ON ((u2.user_id = relations.user_id_2)))
     JOIN relation_type rt ON ((rt.relation_type_id = relations.relation_type_id)));


ALTER TABLE relations_view OWNER TO postgres;

--
-- TOC entry 308 (class 1259 OID 352646)
-- Name: return_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE return_list (
    return_list_id integer NOT NULL,
    return_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE return_list OWNER TO postgres;

--
-- TOC entry 309 (class 1259 OID 352649)
-- Name: return_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW return_list_view AS
 SELECT return_list.return_list_id,
    return_list.return_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    return_list.count,
    return_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = return_list.currency_id)) AS sum_currency_name,
    s.status_name,
    return_list.product_id,
    return_list.status_id,
    return_list.currency_id
   FROM ((return_list
     JOIN products p ON ((p.product_id = return_list.product_id)))
     JOIN status s ON ((s.status_id = return_list.status_id)));


ALTER TABLE return_list_view OWNER TO postgres;

--
-- TOC entry 310 (class 1259 OID 352654)
-- Name: returns; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE returns (
    return_id integer NOT NULL,
    user_id integer,
    return_date timestamp without time zone NOT NULL,
    execution_date timestamp without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE returns OWNER TO postgres;

--
-- TOC entry 311 (class 1259 OID 352657)
-- Name: returns_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW returns_view AS
 SELECT returns.return_id,
    to_char(returns.return_date, 'dd.MM.yyyy hh24:mm'::text) AS return_date,
    to_char(returns.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS client_name,
    u1.user_surname AS client_surname,
    u1.user_phone AS client_phone,
    u1.user_address AS clinet_address,
    ( SELECT clients.firm
           FROM clients
          WHERE (clients.user_id = u1.user_id)) AS client_firm,
    u2.user_name AS employee_name,
    u2.user_surname AS employee_surname,
    u2.user_phone AS employee_phone,
    returns.count,
    returns.sum,
    c.currency_short_name AS currency_name,
    returns.employee_id,
    returns.user_id,
    returns.status_id,
    returns.currency_id
   FROM ((((returns
     JOIN users u1 ON ((u1.user_id = returns.user_id)))
     JOIN users u2 ON ((u2.user_id = returns.employee_id)))
     JOIN status s ON ((s.status_id = returns.status_id)))
     JOIN currencies c ON ((c.currency_id = returns.currency_id)));


ALTER TABLE returns_view OWNER TO postgres;

--
-- TOC entry 312 (class 1259 OID 352662)
-- Name: roles_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW roles_view AS
 SELECT roles.role_id,
    roles.role_code,
    roles.role_name,
    roles.comment
   FROM roles;


ALTER TABLE roles_view OWNER TO postgres;

--
-- TOC entry 313 (class 1259 OID 352666)
-- Name: salaries; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE salaries (
    salary_id integer NOT NULL,
    user_id integer NOT NULL,
    salary_value numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    salary_type_id integer NOT NULL,
    salary_date timestamp without time zone NOT NULL,
    salary_bonus boolean
);


ALTER TABLE salaries OWNER TO postgres;

--
-- TOC entry 314 (class 1259 OID 352669)
-- Name: salary_type; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE salary_type (
    salary_type_id integer NOT NULL,
    salary_type_code character varying(15) NOT NULL,
    salary_type_name character varying(30) NOT NULL
);


ALTER TABLE salary_type OWNER TO postgres;

--
-- TOC entry 315 (class 1259 OID 352672)
-- Name: salaries_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW salaries_view AS
 SELECT salaries.salary_id,
    salaries.user_id,
    u.user_name,
    u.user_surname,
    u.user_phone,
    to_char(salaries.salary_date, 'dd.MM.yyyy hh24:mm'::text) AS salary_date,
    salaries.salary_value,
    c.currency_short_name AS currency_name,
    s.salary_type_name,
    salaries.currency_id,
    salaries.salary_type_id,
    salaries.salary_bonus
   FROM (((salaries
     JOIN users u ON ((u.user_id = salaries.user_id)))
     JOIN currencies c ON ((c.currency_id = salaries.currency_id)))
     JOIN salary_type s ON ((s.salary_type_id = salaries.salary_type_id)));


ALTER TABLE salaries_view OWNER TO postgres;

--
-- TOC entry 316 (class 1259 OID 352677)
-- Name: salary_type_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW salary_type_view AS
 SELECT salary_type.salary_type_id,
    salary_type.salary_type_code,
    salary_type.salary_type_name
   FROM salary_type;


ALTER TABLE salary_type_view OWNER TO postgres;

--
-- TOC entry 317 (class 1259 OID 352681)
-- Name: specification_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE specification_list (
    specification_list_id integer NOT NULL,
    specification_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(20,5) NOT NULL
);


ALTER TABLE specification_list OWNER TO postgres;

--
-- TOC entry 318 (class 1259 OID 352684)
-- Name: specification_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW specification_list_view AS
 SELECT specification_list.specification_list_id,
    specification_list.specification_id,
    p.product_name,
    specification_list.count,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    specification_list.product_id
   FROM (specification_list
     JOIN products p ON ((p.product_id = specification_list.product_id)));


ALTER TABLE specification_list_view OWNER TO postgres;

--
-- TOC entry 319 (class 1259 OID 352688)
-- Name: specifications; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE specifications (
    specification_id integer NOT NULL,
    product_id integer NOT NULL,
    sum numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    employee_id integer NOT NULL,
    specification_date timestamp without time zone NOT NULL
);


ALTER TABLE specifications OWNER TO postgres;

--
-- TOC entry 320 (class 1259 OID 352691)
-- Name: specifications_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW specifications_view AS
 SELECT specifications.specification_id,
    to_char(specifications.specification_date, 'dd.MM.yyyy hh24:mm'::text) AS specification_date,
    p.product_name,
    specifications.sum,
    c.currency_short_name AS currency_name,
    u.user_name AS employee_name,
    u.user_surname AS employee_surname,
    u.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u.user_id)))) AS employee_position_name,
    specifications.product_id,
    specifications.currency_id,
    specifications.employee_id
   FROM (((specifications
     JOIN products p ON ((p.product_id = specifications.product_id)))
     JOIN users u ON ((u.user_id = specifications.employee_id)))
     JOIN currencies c ON ((c.currency_id = specifications.currency_id)));


ALTER TABLE specifications_view OWNER TO postgres;

--
-- TOC entry 321 (class 1259 OID 352696)
-- Name: spoilage; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE spoilage (
    spoilage_id integer NOT NULL,
    spoilage_date timestamp without time zone NOT NULL,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE spoilage OWNER TO postgres;

--
-- TOC entry 322 (class 1259 OID 352699)
-- Name: spoilage_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE spoilage_list (
    spoilage_list_id integer NOT NULL,
    spoilage_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE spoilage_list OWNER TO postgres;

--
-- TOC entry 323 (class 1259 OID 352702)
-- Name: spoilage_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW spoilage_list_view AS
 SELECT spoilage_list.spoilage_list_id,
    spoilage_list.spoilage_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    spoilage_list.count,
    spoilage_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = spoilage_list.currency_id)) AS sum_currency_name,
    s.status_name,
    spoilage_list.product_id,
    spoilage_list.status_id,
    spoilage_list.currency_id
   FROM ((spoilage_list
     JOIN products p ON ((p.product_id = spoilage_list.product_id)))
     JOIN status s ON ((s.status_id = spoilage_list.status_id)));


ALTER TABLE spoilage_list_view OWNER TO postgres;

--
-- TOC entry 324 (class 1259 OID 352707)
-- Name: spoilage_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW spoilage_view AS
 SELECT spoilage.spoilage_id,
    to_char(spoilage.spoilage_date, 'dd.MM.yyyy hh24:mm'::text) AS spoilage_date,
    spoilage.count,
    spoilage.sum,
    c.currency_short_name AS currency_name,
    s.status_name,
    e.user_name,
    e.user_surname,
    e.user_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = e.position_id)) AS position_name,
    spoilage.employee_id,
    spoilage.status_id,
    spoilage.currency_id
   FROM (((spoilage
     JOIN employees_view e ON ((e.user_id = spoilage.employee_id)))
     JOIN currencies c ON ((c.currency_id = spoilage.currency_id)))
     JOIN status s ON ((s.status_id = spoilage.status_id)));


ALTER TABLE spoilage_view OWNER TO postgres;

--
-- TOC entry 325 (class 1259 OID 352712)
-- Name: state; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE state (
    state_id integer NOT NULL,
    universal_id integer NOT NULL,
    status_id integer NOT NULL,
    last_change timestamp with time zone
);


ALTER TABLE state OWNER TO postgres;

--
-- TOC entry 326 (class 1259 OID 352715)
-- Name: state_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW state_view AS
 SELECT state.state_id,
    state.universal_id,
    state.status_id,
    to_char(state.last_change, 'dd.MM.yyyy hh24:mm'::text) AS last_change
   FROM state;


ALTER TABLE state_view OWNER TO postgres;

--
-- TOC entry 327 (class 1259 OID 352719)
-- Name: status_rule; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE status_rule (
    status_rule_id integer NOT NULL,
    operation character varying(50) NOT NULL,
    status_id integer NOT NULL
);


ALTER TABLE status_rule OWNER TO postgres;

--
-- TOC entry 328 (class 1259 OID 352722)
-- Name: status_rule_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW status_rule_view AS
 SELECT status_rule.status_rule_id,
    status_rule.operation,
    s.status_name,
    status_rule.status_id
   FROM (status_rule
     JOIN status s ON ((s.status_id = status_rule.status_id)));


ALTER TABLE status_rule_view OWNER TO postgres;

--
-- TOC entry 329 (class 1259 OID 352726)
-- Name: status_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW status_view AS
 SELECT status.status_id,
    status.status_code,
    status.status_name,
    status.comment
   FROM status;


ALTER TABLE status_view OWNER TO postgres;

--
-- TOC entry 330 (class 1259 OID 352730)
-- Name: stock; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE stock (
    stock_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE stock OWNER TO postgres;

--
-- TOC entry 331 (class 1259 OID 352733)
-- Name: stock_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW stock_view AS
 SELECT stock.stock_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    stock.count,
    stock.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = stock.currency_id)) AS sum_currency_name,
    s.status_name,
    stock.product_id,
    stock.status_id,
    stock.currency_id
   FROM ((stock
     JOIN products p ON ((p.product_id = stock.product_id)))
     JOIN status s ON ((s.status_id = stock.status_id)));


ALTER TABLE stock_view OWNER TO postgres;

--
-- TOC entry 332 (class 1259 OID 352738)
-- Name: subaccount_history; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE subaccount_history (
    subaccount_history_id integer NOT NULL,
    subaccount_id integer NOT NULL,
    start_balance numeric(20,3) NOT NULL,
    current_balance numeric(20,3) NOT NULL,
    from_date date,
    till_date date
);


ALTER TABLE subaccount_history OWNER TO postgres;

--
-- TOC entry 333 (class 1259 OID 352741)
-- Name: subaccount_history_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW subaccount_history_view AS
 SELECT subaccount_history.subaccount_history_id,
    subaccount_history.subaccount_id,
    subaccount_history.start_balance,
    subaccount_history.current_balance,
    subaccount_history.from_date,
    subaccount_history.till_date
   FROM subaccount_history;


ALTER TABLE subaccount_history_view OWNER TO postgres;

--
-- TOC entry 334 (class 1259 OID 352745)
-- Name: subaccounts_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW subaccounts_view AS
 SELECT subaccounts.subaccount_id,
    a.account_id,
    a.account_number,
    subaccounts.subaccount_number,
    subaccounts.start_balance,
    subaccounts.current_balance,
    c.currency_short_name AS currency_name,
    s.status_name,
    subaccounts.currency_id,
    subaccounts.status_id,
    to_char((subaccounts.date_opened)::timestamp with time zone, 'dd.MM.yyyy'::text) AS date_opened,
    to_char((subaccounts.date_closed)::timestamp with time zone, 'dd.MM.yyyy'::text) AS date_closed,
    subaccounts.details
   FROM (((subaccounts
     JOIN accounts a ON ((a.account_id = subaccounts.account_id)))
     JOIN currencies c ON ((c.currency_id = subaccounts.currency_id)))
     JOIN status s ON ((s.status_id = subaccounts.status_id)));


ALTER TABLE subaccounts_view OWNER TO postgres;

--
-- TOC entry 335 (class 1259 OID 352750)
-- Name: taxes; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE taxes (
    tax_id integer NOT NULL,
    tax_name character(100) NOT NULL,
    tax_code character varying(15) NOT NULL,
    fixed_value numeric(20,3),
    percent_value integer,
    formula_value character varying(100)
);


ALTER TABLE taxes OWNER TO postgres;

--
-- TOC entry 336 (class 1259 OID 352753)
-- Name: taxes_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW taxes_view AS
 SELECT taxes.tax_id,
    taxes.tax_name,
    taxes.tax_code,
    taxes.fixed_value,
    taxes.percent_value,
    taxes.formula_value
   FROM taxes;


ALTER TABLE taxes_view OWNER TO postgres;

--
-- TOC entry 337 (class 1259 OID 352757)
-- Name: timesheet; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE timesheet (
    timesheet_id integer NOT NULL,
    salary_id integer NOT NULL,
    worked_time numeric(4,2) NOT NULL,
    timesheet_date date NOT NULL
);


ALTER TABLE timesheet OWNER TO postgres;

--
-- TOC entry 338 (class 1259 OID 352760)
-- Name: timesheet_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW timesheet_view AS
 SELECT timesheet.timesheet_id,
    s.user_name,
    s.user_surname,
    s.user_phone,
    to_char((timesheet.timesheet_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS timesheet_date,
    timesheet.worked_time,
    timesheet.salary_id
   FROM (timesheet
     JOIN salaries_view s ON ((s.salary_id = timesheet.salary_id)));


ALTER TABLE timesheet_view OWNER TO postgres;

--
-- TOC entry 339 (class 1259 OID 352764)
-- Name: transport_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE transport_list (
    transport_list_id integer NOT NULL,
    transport_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE transport_list OWNER TO postgres;

--
-- TOC entry 340 (class 1259 OID 352767)
-- Name: transport_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW transport_list_view AS
 SELECT transport_list.transport_list_id,
    transport_list.transport_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    transport_list.count,
    transport_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = transport_list.currency_id)) AS sum_currency_name,
    s.status_name,
    transport_list.product_id,
    transport_list.status_id,
    transport_list.currency_id
   FROM ((transport_list
     JOIN products p ON ((p.product_id = transport_list.product_id)))
     JOIN status s ON ((s.status_id = transport_list.status_id)));


ALTER TABLE transport_list_view OWNER TO postgres;

--
-- TOC entry 341 (class 1259 OID 352772)
-- Name: transports; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE transports (
    transport_id integer NOT NULL,
    user_id integer NOT NULL,
    transport_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE transports OWNER TO postgres;

--
-- TOC entry 342 (class 1259 OID 352775)
-- Name: transports_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW transports_view AS
 SELECT transports.transport_id,
    to_char(transports.transport_date, 'dd.MM.yyyy hh24:mm'::text) AS transport_date,
    to_char(transports.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    transports.count,
    transports.sum,
    c.currency_short_name AS currency_name,
    transports.employee_id,
    transports.user_id,
    transports.status_id,
    transports.currency_id
   FROM ((((transports
     JOIN users u1 ON ((u1.user_id = transports.user_id)))
     JOIN users u2 ON ((u2.user_id = transports.employee_id)))
     JOIN status s ON ((s.status_id = transports.status_id)))
     JOIN currencies c ON ((c.currency_id = transports.currency_id)));


ALTER TABLE transports_view OWNER TO postgres;

--
-- TOC entry 343 (class 1259 OID 352780)
-- Name: users_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW users_view AS
 SELECT users.user_id,
    users.user_email,
    users.user_name,
    users.user_surname,
    users.user_phone,
    users.user_address,
    r.role_name,
    users.password,
    users.activated,
    users.role_id
   FROM (users
     JOIN roles r ON ((r.role_id = users.role_id)));


ALTER TABLE users_view OWNER TO postgres;

--
-- TOC entry 344 (class 1259 OID 352784)
-- Name: withdrawals; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE withdrawals (
    withdrawal_id integer NOT NULL,
    withdrawal_date timestamp without time zone NOT NULL,
    withdrawal_value numeric(20,3) NOT NULL,
    user_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE withdrawals OWNER TO postgres;

--
-- TOC entry 345 (class 1259 OID 352787)
-- Name: withdrawals_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW withdrawals_view AS
 SELECT withdrawals.withdrawal_id,
    to_char(withdrawals.withdrawal_date, 'dd.MM.yyyy hh24:mm'::text) AS withdrawal_date,
    withdrawals.withdrawal_value,
    c.currency_short_name AS currency_name,
    withdrawals.user_id,
    withdrawals.currency_id
   FROM (withdrawals
     JOIN currencies c ON ((c.currency_id = withdrawals.currency_id)));


ALTER TABLE withdrawals_view OWNER TO postgres;

--
-- TOC entry 346 (class 1259 OID 352791)
-- Name: write_off_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE write_off_list (
    write_off_list_id integer NOT NULL,
    write_off_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE write_off_list OWNER TO postgres;

--
-- TOC entry 347 (class 1259 OID 352794)
-- Name: write_off_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW write_off_list_view AS
 SELECT write_off_list.write_off_list_id,
    write_off_list.write_off_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    write_off_list.count,
    write_off_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = write_off_list.currency_id)) AS sum_currency_name,
    s.status_name,
    write_off_list.product_id,
    write_off_list.status_id,
    write_off_list.currency_id
   FROM ((write_off_list
     JOIN products p ON ((p.product_id = write_off_list.product_id)))
     JOIN status s ON ((s.status_id = write_off_list.status_id)));


ALTER TABLE write_off_list_view OWNER TO postgres;

--
-- TOC entry 348 (class 1259 OID 352799)
-- Name: write_off_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE write_off_raw_list (
    write_off_raw_list_id integer NOT NULL,
    write_off_raw_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE write_off_raw_list OWNER TO postgres;

--
-- TOC entry 349 (class 1259 OID 352802)
-- Name: write_off_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW write_off_raw_list_view AS
 SELECT write_off_raw_list.write_off_raw_list_id,
    write_off_raw_list.write_off_raw_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    write_off_raw_list.count,
    write_off_raw_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = write_off_raw_list.currency_id)) AS sum_currency_name,
    s.status_name,
    write_off_raw_list.product_id,
    write_off_raw_list.status_id,
    write_off_raw_list.currency_id
   FROM ((write_off_raw_list
     JOIN products p ON ((p.product_id = write_off_raw_list.product_id)))
     JOIN status s ON ((s.status_id = write_off_raw_list.status_id)));


ALTER TABLE write_off_raw_list_view OWNER TO postgres;

--
-- TOC entry 350 (class 1259 OID 352807)
-- Name: write_off_raws; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE write_off_raws (
    write_off_raw_id integer NOT NULL,
    user_id integer,
    write_off_raw_date timestamp without time zone NOT NULL,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE write_off_raws OWNER TO postgres;

--
-- TOC entry 351 (class 1259 OID 352810)
-- Name: write_off_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW write_off_raws_view AS
 SELECT write_off_raws.write_off_raw_id,
    to_char(write_off_raws.write_off_raw_date, 'dd.MM.yyyy hh24:mm'::text) AS write_off_raw_date,
    s.status_code,
    s.status_name,
    u1.user_name AS employee_name,
    u1.user_surname AS employee_surname,
    u1.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS employee_position_name,
    u2.user_name AS stock_employee_name,
    u2.user_surname AS stock_employee_surname,
    u2.user_phone AS stock_employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS stock_employee_position_name,
    write_off_raws.count,
    write_off_raws.sum,
    c.currency_short_name AS currency_name,
    write_off_raws.employee_id,
    write_off_raws.user_id,
    write_off_raws.status_id,
    write_off_raws.currency_id
   FROM ((((write_off_raws
     JOIN users u1 ON ((u1.user_id = write_off_raws.user_id)))
     JOIN users u2 ON ((u2.user_id = write_off_raws.employee_id)))
     JOIN status s ON ((s.status_id = write_off_raws.status_id)))
     JOIN currencies c ON ((c.currency_id = write_off_raws.currency_id)));


ALTER TABLE write_off_raws_view OWNER TO postgres;

--
-- TOC entry 352 (class 1259 OID 352815)
-- Name: write_offs; Type: TABLE; Schema: OrmasSchema; Owner: postgres
--

CREATE TABLE write_offs (
    write_off_id integer NOT NULL,
    user_id integer,
    write_off_date timestamp without time zone NOT NULL,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


ALTER TABLE write_offs OWNER TO postgres;

--
-- TOC entry 353 (class 1259 OID 352818)
-- Name: write_offs_view; Type: VIEW; Schema: OrmasSchema; Owner: postgres
--

CREATE VIEW write_offs_view AS
 SELECT write_offs.write_off_id,
    to_char(write_offs.write_off_date, 'dd.MM.yyyy hh24:mm'::text) AS write_off_date,
    s.status_code,
    s.status_name,
    u1.user_name AS client_name,
    u1.user_surname AS client_surname,
    u1.user_phone AS client_phone,
    u1.user_address AS clinet_address,
    ( SELECT clients.firm
           FROM clients
          WHERE (clients.user_id = u1.user_id)) AS client_firm,
    u2.user_name AS employee_name,
    u2.user_surname AS employee_surname,
    u2.user_phone AS employee_phone,
    write_offs.count,
    write_offs.sum,
    c.currency_short_name AS currency_name,
    write_offs.employee_id,
    write_offs.user_id,
    write_offs.status_id,
    write_offs.currency_id
   FROM ((((write_offs
     JOIN users u1 ON ((u1.user_id = write_offs.user_id)))
     JOIN users u2 ON ((u2.user_id = write_offs.employee_id)))
     JOIN status s ON ((s.status_id = write_offs.status_id)))
     JOIN currencies c ON ((c.currency_id = write_offs.currency_id)));


ALTER TABLE write_offs_view OWNER TO postgres;

--
-- TOC entry 2663 (class 2606 OID 352824)
-- Name: access_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY accesses
    ADD CONSTRAINT access_pkey PRIMARY KEY (access_id);


--
-- TOC entry 2667 (class 2606 OID 352826)
-- Name: account_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY account_history
    ADD CONSTRAINT account_history_pkey PRIMARY KEY (account_history_id);


--
-- TOC entry 2671 (class 2606 OID 352828)
-- Name: account_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY accounts
    ADD CONSTRAINT account_pkey PRIMARY KEY (account_id);


--
-- TOC entry 2669 (class 2606 OID 352830)
-- Name: account_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY account_type
    ADD CONSTRAINT account_type_pkey PRIMARY KEY (account_type_id);


--
-- TOC entry 2673 (class 2606 OID 352832)
-- Name: balance_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY balances
    ADD CONSTRAINT balance_pkey PRIMARY KEY (balance_id);


--
-- TOC entry 2681 (class 2606 OID 352834)
-- Name: char_of_account_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY chart_of_accounts
    ADD CONSTRAINT char_of_account_pkey PRIMARY KEY (chart_of_account_id);


--
-- TOC entry 2683 (class 2606 OID 352836)
-- Name: client_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY clients
    ADD CONSTRAINT client_pkey PRIMARY KEY (user_id);


--
-- TOC entry 2689 (class 2606 OID 352838)
-- Name: company_account_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY company_account
    ADD CONSTRAINT company_account_pkey PRIMARY KEY (company_account_id);


--
-- TOC entry 2691 (class 2606 OID 352840)
-- Name: company_employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY company_employee
    ADD CONSTRAINT company_employee_pkey PRIMARY KEY (company_employee_id);


--
-- TOC entry 2687 (class 2606 OID 352842)
-- Name: company_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY companies
    ADD CONSTRAINT company_pkey PRIMARY KEY (company_id);


--
-- TOC entry 2693 (class 2606 OID 352844)
-- Name: consume_product_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY consume_product_list
    ADD CONSTRAINT consume_product_list_pkey PRIMARY KEY (consume_product_list_id);


--
-- TOC entry 2701 (class 2606 OID 352846)
-- Name: consume_product_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY consume_products
    ADD CONSTRAINT consume_product_pkey PRIMARY KEY (consume_product_id);


--
-- TOC entry 2707 (class 2606 OID 352848)
-- Name: consume_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY consume_raw_list
    ADD CONSTRAINT consume_raw_list_pkey PRIMARY KEY (consume_raw_list_id);


--
-- TOC entry 2709 (class 2606 OID 352850)
-- Name: consume_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY consume_raws
    ADD CONSTRAINT consume_raw_pkey PRIMARY KEY (consume_raw_id);


--
-- TOC entry 2675 (class 2606 OID 352852)
-- Name: currency_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY currencies
    ADD CONSTRAINT currency_pkey PRIMARY KEY (currency_id);


--
-- TOC entry 2703 (class 2606 OID 352854)
-- Name: employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY employees
    ADD CONSTRAINT employee_pkey PRIMARY KEY (user_id);


--
-- TOC entry 2712 (class 2606 OID 352856)
-- Name: entry_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY entries
    ADD CONSTRAINT entry_pkey PRIMARY KEY (entry_id);


--
-- TOC entry 2714 (class 2606 OID 352858)
-- Name: entry_routing_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY entry_routing
    ADD CONSTRAINT entry_routing_pkey PRIMARY KEY (entry_routing_id);


--
-- TOC entry 2716 (class 2606 OID 352860)
-- Name: financial_report_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY financial_report
    ADD CONSTRAINT financial_report_pkey PRIMARY KEY (financial_report_id);


--
-- TOC entry 2718 (class 2606 OID 352862)
-- Name: inventorization_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY inventorization_list
    ADD CONSTRAINT inventorization_list_pkey PRIMARY KEY (inventorization_list_id);


--
-- TOC entry 2720 (class 2606 OID 352864)
-- Name: inventorization_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY inventorizations
    ADD CONSTRAINT inventorization_pkey PRIMARY KEY (inventorization_id);


--
-- TOC entry 2722 (class 2606 OID 352866)
-- Name: jobprice_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY jobprice
    ADD CONSTRAINT jobprice_pkey PRIMARY KEY (jobprice_id);


--
-- TOC entry 2724 (class 2606 OID 352868)
-- Name: jobsheet_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY jobsheet
    ADD CONSTRAINT jobsheet_pkey PRIMARY KEY (jobsheet_id);


--
-- TOC entry 2695 (class 2606 OID 352870)
-- Name: measure_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY measures
    ADD CONSTRAINT measure_pkey PRIMARY KEY (measure_id);


--
-- TOC entry 2661 (class 2606 OID 352872)
-- Name: menu_item_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY access_items
    ADD CONSTRAINT menu_item_pkey PRIMARY KEY (access_item_id);


--
-- TOC entry 2726 (class 2606 OID 352874)
-- Name: net_cost_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY net_cost
    ADD CONSTRAINT net_cost_pkey PRIMARY KEY (net_cost_id);


--
-- TOC entry 2728 (class 2606 OID 352876)
-- Name: order_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY order_list
    ADD CONSTRAINT order_list_pkey PRIMARY KEY (order_list_id);


--
-- TOC entry 2736 (class 2606 OID 352878)
-- Name: order_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY orders
    ADD CONSTRAINT order_pkey PRIMARY KEY (order_id);


--
-- TOC entry 2730 (class 2606 OID 352880)
-- Name: order_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY order_raw_list
    ADD CONSTRAINT order_raw_list_pkey PRIMARY KEY (order_raw_list_id);


--
-- TOC entry 2732 (class 2606 OID 352882)
-- Name: order_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY order_raws
    ADD CONSTRAINT order_raw_pkey PRIMARY KEY (order_raw_id);


--
-- TOC entry 2738 (class 2606 OID 352884)
-- Name: payment_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY payments
    ADD CONSTRAINT payment_pkey PRIMARY KEY (payment_id);


--
-- TOC entry 2740 (class 2606 OID 352886)
-- Name: payslip_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY payslips
    ADD CONSTRAINT payslip_pkey PRIMARY KEY (payslip_id);


--
-- TOC entry 2742 (class 2606 OID 352888)
-- Name: percent_rate_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY percent_rate
    ADD CONSTRAINT percent_rate_pkey PRIMARY KEY (percent_rate_id);


--
-- TOC entry 2744 (class 2606 OID 352890)
-- Name: photo_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY photos
    ADD CONSTRAINT photo_pkey PRIMARY KEY (photo_id);


--
-- TOC entry 2705 (class 2606 OID 352892)
-- Name: position_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY positions
    ADD CONSTRAINT position_pkey PRIMARY KEY (position_id);


--
-- TOC entry 2746 (class 2606 OID 352894)
-- Name: price_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY prices
    ADD CONSTRAINT price_pkey PRIMARY KEY (price_id);


--
-- TOC entry 2697 (class 2606 OID 352896)
-- Name: product_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY products
    ADD CONSTRAINT product_pkey PRIMARY KEY (product_id, company_id);


--
-- TOC entry 2748 (class 2606 OID 352898)
-- Name: product_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY product_type
    ADD CONSTRAINT product_type_pkey PRIMARY KEY (product_type_id);


--
-- TOC entry 2752 (class 2606 OID 352900)
-- Name: production_consume_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production_consume_raw_list
    ADD CONSTRAINT production_consume_raw_list_pkey PRIMARY KEY (consume_raw_list_id);


--
-- TOC entry 2754 (class 2606 OID 352902)
-- Name: production_consume_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production_consume_raws
    ADD CONSTRAINT production_consume_raw_pkey PRIMARY KEY (consume_raw_id);


--
-- TOC entry 2756 (class 2606 OID 352904)
-- Name: production_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production_list
    ADD CONSTRAINT production_list_pkey PRIMARY KEY (production_list_id);


--
-- TOC entry 2750 (class 2606 OID 352906)
-- Name: production_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production
    ADD CONSTRAINT production_pkey PRIMARY KEY (production_id);


--
-- TOC entry 2760 (class 2606 OID 352908)
-- Name: production_plan_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production_plan_list
    ADD CONSTRAINT production_plan_list_pkey PRIMARY KEY (production_plan_list_id);


--
-- TOC entry 2758 (class 2606 OID 352910)
-- Name: production_plan_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production_plan
    ADD CONSTRAINT production_plan_pkey PRIMARY KEY (production_plan_id);


--
-- TOC entry 2762 (class 2606 OID 352912)
-- Name: production_stock_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY production_stock
    ADD CONSTRAINT production_stock_pkey PRIMARY KEY (production_stock_id);


--
-- TOC entry 2734 (class 2606 OID 352914)
-- Name: purveyor_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY purveyors
    ADD CONSTRAINT purveyor_pkey PRIMARY KEY (user_id);


--
-- TOC entry 2764 (class 2606 OID 352916)
-- Name: receipt_product_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY receipt_product_list
    ADD CONSTRAINT receipt_product_list_pkey PRIMARY KEY (receipt_product_list_id);


--
-- TOC entry 2766 (class 2606 OID 352918)
-- Name: receipt_product_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY receipt_products
    ADD CONSTRAINT receipt_product_pkey PRIMARY KEY (receipt_product_id);


--
-- TOC entry 2768 (class 2606 OID 352920)
-- Name: receipt_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY receipt_raw_list
    ADD CONSTRAINT receipt_raw_list_pkey PRIMARY KEY (receipt_raw_list_id);


--
-- TOC entry 2770 (class 2606 OID 352922)
-- Name: receipt_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY receipt_raws
    ADD CONSTRAINT receipt_raw_pkey PRIMARY KEY (receipt_raw_id);


--
-- TOC entry 2772 (class 2606 OID 352924)
-- Name: refund_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY refunds
    ADD CONSTRAINT refund_pkey PRIMARY KEY (refund_id);


--
-- TOC entry 2685 (class 2606 OID 352926)
-- Name: region_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY locations
    ADD CONSTRAINT region_pkey PRIMARY KEY (location_id);


--
-- TOC entry 2774 (class 2606 OID 352928)
-- Name: relarion_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY relation_type
    ADD CONSTRAINT relarion_type_pkey PRIMARY KEY (relation_type_id);


--
-- TOC entry 2776 (class 2606 OID 352930)
-- Name: relation_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY relations
    ADD CONSTRAINT relation_pkey PRIMARY KEY (relation_id);


--
-- TOC entry 2778 (class 2606 OID 352932)
-- Name: return_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY return_list
    ADD CONSTRAINT return_list_pkey PRIMARY KEY (return_list_id);


--
-- TOC entry 2780 (class 2606 OID 352934)
-- Name: return_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY returns
    ADD CONSTRAINT return_pkey PRIMARY KEY (return_id);


--
-- TOC entry 2665 (class 2606 OID 352936)
-- Name: role_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY roles
    ADD CONSTRAINT role_pkey PRIMARY KEY (role_id);


--
-- TOC entry 2782 (class 2606 OID 352938)
-- Name: salary_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY salaries
    ADD CONSTRAINT salary_pkey PRIMARY KEY (salary_id);


--
-- TOC entry 2784 (class 2606 OID 352940)
-- Name: salary_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY salary_type
    ADD CONSTRAINT salary_type_pkey PRIMARY KEY (salary_type_id);


--
-- TOC entry 2786 (class 2606 OID 352942)
-- Name: specification_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY specification_list
    ADD CONSTRAINT specification_list_pkey PRIMARY KEY (specification_list_id);


--
-- TOC entry 2788 (class 2606 OID 352944)
-- Name: specification_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY specifications
    ADD CONSTRAINT specification_pkey PRIMARY KEY (specification_id);


--
-- TOC entry 2792 (class 2606 OID 352946)
-- Name: spoilage_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY spoilage_list
    ADD CONSTRAINT spoilage_list_pkey PRIMARY KEY (spoilage_list_id);


--
-- TOC entry 2790 (class 2606 OID 352948)
-- Name: spoilage_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY spoilage
    ADD CONSTRAINT spoilage_pkey PRIMARY KEY (spoilage_id);


--
-- TOC entry 2794 (class 2606 OID 352950)
-- Name: state_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY state
    ADD CONSTRAINT state_pkey PRIMARY KEY (state_id);


--
-- TOC entry 2699 (class 2606 OID 352952)
-- Name: status_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY status
    ADD CONSTRAINT status_pkey PRIMARY KEY (status_id);


--
-- TOC entry 2796 (class 2606 OID 352954)
-- Name: status_rule_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY status_rule
    ADD CONSTRAINT status_rule_pkey PRIMARY KEY (status_rule_id);


--
-- TOC entry 2798 (class 2606 OID 352956)
-- Name: stock_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY stock
    ADD CONSTRAINT stock_pkey PRIMARY KEY (stock_id);


--
-- TOC entry 2800 (class 2606 OID 352958)
-- Name: subaccount_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY subaccount_history
    ADD CONSTRAINT subaccount_history_pkey PRIMARY KEY (subaccount_history_id);


--
-- TOC entry 2677 (class 2606 OID 352960)
-- Name: subaccount_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY subaccounts
    ADD CONSTRAINT subaccount_pkey PRIMARY KEY (subaccount_id);


--
-- TOC entry 2802 (class 2606 OID 352962)
-- Name: tax_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY taxes
    ADD CONSTRAINT tax_pkey PRIMARY KEY (tax_id);


--
-- TOC entry 2804 (class 2606 OID 352964)
-- Name: timesheet_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY timesheet
    ADD CONSTRAINT timesheet_pkey PRIMARY KEY (timesheet_id);


--
-- TOC entry 2806 (class 2606 OID 352966)
-- Name: transport_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY transport_list
    ADD CONSTRAINT transport_list_pkey PRIMARY KEY (transport_list_id);


--
-- TOC entry 2808 (class 2606 OID 352968)
-- Name: transport_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY transports
    ADD CONSTRAINT transport_pkey PRIMARY KEY (transport_id);


--
-- TOC entry 2679 (class 2606 OID 352970)
-- Name: user_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY users
    ADD CONSTRAINT user_pkey PRIMARY KEY (user_id);


--
-- TOC entry 2816 (class 2606 OID 352972)
-- Name: wite_off_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY write_off_raws
    ADD CONSTRAINT wite_off_raw_pkey PRIMARY KEY (write_off_raw_id);


--
-- TOC entry 2810 (class 2606 OID 352974)
-- Name: withdrawal_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY withdrawals
    ADD CONSTRAINT withdrawal_pkey PRIMARY KEY (withdrawal_id);


--
-- TOC entry 2812 (class 2606 OID 352976)
-- Name: write_off_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY write_off_list
    ADD CONSTRAINT write_off_list_pkey PRIMARY KEY (write_off_list_id);


--
-- TOC entry 2818 (class 2606 OID 352978)
-- Name: write_off_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY write_offs
    ADD CONSTRAINT write_off_pkey PRIMARY KEY (write_off_id);


--
-- TOC entry 2814 (class 2606 OID 352980)
-- Name: write_off_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY write_off_raw_list
    ADD CONSTRAINT write_off_raw_list_pkey PRIMARY KEY (write_off_raw_list_id);


--
-- TOC entry 2710 (class 1259 OID 352981)
-- Name: entry_date_index; Type: INDEX; Schema: OrmasSchema; Owner: postgres
--

CREATE INDEX entry_date_index ON entries USING btree (entry_date DESC);


--
-- TOC entry 2819 (class 2606 OID 352982)
-- Name: access_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY accesses
    ADD CONSTRAINT access_fkey FOREIGN KEY (access_item_id) REFERENCES access_items(access_item_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2820 (class 2606 OID 352987)
-- Name: balance_subaccount_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY balances
    ADD CONSTRAINT balance_subaccount_fkey FOREIGN KEY (subaccount_id) REFERENCES subaccounts(subaccount_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2821 (class 2606 OID 352992)
-- Name: balance_user_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY balances
    ADD CONSTRAINT balance_user_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2822 (class 2606 OID 352997)
-- Name: client_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY clients
    ADD CONSTRAINT client_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2823 (class 2606 OID 353002)
-- Name: employee_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY employees
    ADD CONSTRAINT employee_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2824 (class 2606 OID 353007)
-- Name: purveyor_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY purveyors
    ADD CONSTRAINT purveyor_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 2825 (class 2606 OID 353012)
-- Name: salary_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: postgres
--

ALTER TABLE ONLY salaries
    ADD CONSTRAINT salary_fkey FOREIGN KEY (user_id) REFERENCES users(user_id);


--
-- TOC entry 3031 (class 0 OID 0)
-- Dependencies: 7
-- Name: OrmasSchema; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA "OrmasSchema" FROM PUBLIC;
REVOKE ALL ON SCHEMA "OrmasSchema" FROM postgres;
GRANT ALL ON SCHEMA "OrmasSchema" TO postgres;
GRANT ALL ON SCHEMA "OrmasSchema" TO PUBLIC;


--
-- TOC entry 3033 (class 0 OID 0)
-- Dependencies: 8
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


-- Completed on 2018-07-03 12:06:33

--
-- PostgreSQL database dump complete
--

