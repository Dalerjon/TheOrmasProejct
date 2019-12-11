--
-- PostgreSQL database dump
--

-- Dumped from database version 9.5.4
-- Dumped by pg_dump version 9.5.4

-- Started on 2019-11-24 20:01:01

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 7 (class 2615 OID 741216)
-- Name: OrmasSchema; Type: SCHEMA; Schema: -; Owner: -
--

CREATE SCHEMA "OrmasSchema";


--
-- TOC entry 3357 (class 0 OID 0)
-- Dependencies: 7
-- Name: SCHEMA "OrmasSchema"; Type: COMMENT; Schema: -; Owner: -
--

COMMENT ON SCHEMA "OrmasSchema" IS 'Ormas application schema';


--
-- TOC entry 1 (class 3079 OID 12355)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: -
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 3361 (class 0 OID 0)
-- Dependencies: 1
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: -
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = "OrmasSchema", pg_catalog;

--
-- TOC entry 411 (class 1255 OID 741217)
-- Name: getcurrentdate(); Type: FUNCTION; Schema: OrmasSchema; Owner: -
--

CREATE FUNCTION getcurrentdate() RETURNS text
    LANGUAGE plpgsql IMMUTABLE
    AS $$
DECLARE 
    currentdate text;
BEGIN
 currentdate := to_char(now()::timestamp(0), 'dd.MM.yyyy hh24:mm');
 return currentdate;
END;
$$;


--
-- TOC entry 182 (class 1259 OID 741218)
-- Name: acc_seq; Type: SEQUENCE; Schema: OrmasSchema; Owner: -
--

CREATE SEQUENCE acc_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 999999999
    CACHE 1;


SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 183 (class 1259 OID 741220)
-- Name: access_items; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE access_items (
    access_item_id integer NOT NULL,
    access_item_eng character varying(30) NOT NULL,
    access_item_ru character varying(30) NOT NULL,
    access_division character varying(20) NOT NULL
);


--
-- TOC entry 184 (class 1259 OID 741223)
-- Name: access_items_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW access_items_view AS
 SELECT access_items.access_item_id,
    access_items.access_item_eng,
    access_items.access_item_ru AS access_iterm_ru,
    access_items.access_division
   FROM access_items;


--
-- TOC entry 185 (class 1259 OID 741227)
-- Name: accesses; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE accesses (
    access_id integer NOT NULL,
    role_id integer NOT NULL,
    access_item_id integer NOT NULL
);


--
-- TOC entry 186 (class 1259 OID 741230)
-- Name: roles; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE roles (
    role_id integer NOT NULL,
    role_code character varying(20) NOT NULL,
    role_name character varying(50) NOT NULL,
    comment character varying(100)
);


--
-- TOC entry 187 (class 1259 OID 741233)
-- Name: accesses_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 188 (class 1259 OID 741237)
-- Name: account_history; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE account_history (
    account_history_id integer NOT NULL,
    account_id integer NOT NULL,
    account_number character varying(20) NOT NULL,
    start_balance numeric(20,3),
    current_balance numeric(20,3),
    from_date date,
    till_date date
);


--
-- TOC entry 189 (class 1259 OID 741240)
-- Name: account_history_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 190 (class 1259 OID 741244)
-- Name: account_type; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE account_type (
    account_type_id integer NOT NULL,
    account_type_name character varying(50) NOT NULL,
    account_type_number integer NOT NULL,
    comment character varying(100)
);


--
-- TOC entry 191 (class 1259 OID 741247)
-- Name: account_type_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW account_type_view AS
 SELECT account_type.account_type_id,
    account_type.account_type_name,
    account_type.account_type_number,
    account_type.comment
   FROM account_type;


--
-- TOC entry 192 (class 1259 OID 741251)
-- Name: accountable; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE accountable (
    employee_id integer NOT NULL,
    information character varying(200)
);


--
-- TOC entry 193 (class 1259 OID 741254)
-- Name: accountable_transaction; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE accountable_transaction (
    accountable_transaction_id integer NOT NULL,
    accountable_id integer NOT NULL,
    start_value numeric(20,3),
    end_value numeric(20,3),
    operation_id integer NOT NULL
);


--
-- TOC entry 194 (class 1259 OID 741257)
-- Name: accountable_transaction_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW accountable_transaction_view AS
 SELECT accountable_transaction.accountable_transaction_id,
    accountable_transaction.accountable_id,
    accountable_transaction.start_value,
    accountable_transaction.end_value,
    accountable_transaction.operation_id
   FROM accountable_transaction;


--
-- TOC entry 195 (class 1259 OID 741261)
-- Name: users; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 196 (class 1259 OID 741264)
-- Name: accountable_veiw; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW accountable_veiw AS
 SELECT users.user_id,
    users.user_name,
    users.user_surname,
    accountable.information,
    users.user_phone,
    users.user_address,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = users.role_id)) AS role_name
   FROM (accountable
     JOIN users ON ((users.user_id = accountable.employee_id)));


--
-- TOC entry 197 (class 1259 OID 741268)
-- Name: accounts; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE accounts (
    account_id integer NOT NULL,
    account_number character varying(20) NOT NULL,
    start_balance numeric(20,3) NOT NULL,
    current_balance numeric(20,3) NOT NULL
);


--
-- TOC entry 198 (class 1259 OID 741271)
-- Name: accounts_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW accounts_view AS
 SELECT accounts.account_id,
    accounts.account_number,
    accounts.start_balance,
    accounts.current_balance
   FROM accounts;


--
-- TOC entry 406 (class 1259 OID 742337)
-- Name: amortize_group; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE amortize_group (
    amortize_group_id integer NOT NULL,
    group_number integer,
    from_month integer,
    to_month integer
);


--
-- TOC entry 407 (class 1259 OID 742342)
-- Name: amortize_group_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW amortize_group_view AS
 SELECT amortize_group.amortize_group_id,
    amortize_group.group_number,
    amortize_group.from_month,
    amortize_group.to_month
   FROM amortize_group;


--
-- TOC entry 398 (class 1259 OID 742286)
-- Name: amortize_type; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE amortize_type (
    amortize_type_id integer NOT NULL,
    amortize_type_name character varying(100),
    amortize_type_code character varying(50),
    amortize_percent integer,
    value_depends_on_sales numeric(17,3),
    amortize_year integer,
    amortize_coefficient numeric(17,5)
);


--
-- TOC entry 402 (class 1259 OID 742312)
-- Name: amortize_type_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW amortize_type_view AS
 SELECT amortize_type.amortize_type_id,
    amortize_type.amortize_type_name,
    amortize_type.amortize_type_code,
    amortize_type.amortize_percent,
    amortize_type.value_depends_on_sales,
    amortize_type.amortize_year,
    amortize_type.amortize_coefficient
   FROM amortize_type;


--
-- TOC entry 199 (class 1259 OID 741275)
-- Name: balance_payment; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE balance_payment (
    balance_payment_id integer NOT NULL,
    balance_id integer NOT NULL,
    payment_id integer NOT NULL
);


--
-- TOC entry 200 (class 1259 OID 741278)
-- Name: balance_payment_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW balance_payment_view AS
 SELECT balance_payment.balance_payment_id,
    balance_payment.balance_id,
    balance_payment.payment_id
   FROM balance_payment;


--
-- TOC entry 201 (class 1259 OID 741282)
-- Name: balance_payslip; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE balance_payslip (
    balance_payslip_id integer NOT NULL,
    balance_id integer NOT NULL,
    payslip_id integer NOT NULL
);


--
-- TOC entry 202 (class 1259 OID 741285)
-- Name: balance_payslip_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW balance_payslip_view AS
 SELECT balance_payslip.balance_payslip_id,
    balance_payslip.balance_id,
    balance_payslip.payslip_id
   FROM balance_payslip;


--
-- TOC entry 203 (class 1259 OID 741289)
-- Name: balance_refund; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE balance_refund (
    balance_refund_id integer NOT NULL,
    balance_id integer NOT NULL,
    refund_id integer NOT NULL
);


--
-- TOC entry 204 (class 1259 OID 741292)
-- Name: balance_refund_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW balance_refund_view AS
 SELECT balance_refund.balance_refund_id,
    balance_refund.balance_id,
    balance_refund.refund_id
   FROM balance_refund;


--
-- TOC entry 205 (class 1259 OID 741296)
-- Name: balance_withdrawal; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE balance_withdrawal (
    balance_withdrawal_id integer NOT NULL,
    balance_id integer NOT NULL,
    withdrawal_id integer NOT NULL
);


--
-- TOC entry 206 (class 1259 OID 741299)
-- Name: balance_withdrawal_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW balance_withdrawal_view AS
 SELECT balance_withdrawal.balance_withdrawal_id,
    balance_withdrawal.balance_id,
    balance_withdrawal.withdrawal_id
   FROM balance_withdrawal;


--
-- TOC entry 207 (class 1259 OID 741303)
-- Name: balances; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE balances (
    balance_id integer NOT NULL,
    user_id integer NOT NULL,
    subaccount_id integer NOT NULL
);


--
-- TOC entry 208 (class 1259 OID 741306)
-- Name: currencies; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE currencies (
    currency_id integer NOT NULL,
    currency_code integer,
    currency_short_name character varying(3),
    currency_name character varying(20),
    currency_unit integer NOT NULL,
    currency_main_trade boolean
);


--
-- TOC entry 209 (class 1259 OID 741309)
-- Name: subaccounts; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 210 (class 1259 OID 741312)
-- Name: balances_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW balances_view AS
 SELECT balances.balance_id,
    u.user_name,
    u.user_surname,
    s.subaccount_number,
    s.current_balance,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = s.currency_id)) AS currency_name,
    balances.user_id,
    balances.subaccount_id
   FROM ((balances
     JOIN users u ON ((u.user_id = balances.user_id)))
     JOIN subaccounts s ON ((s.subaccount_id = balances.subaccount_id)));


--
-- TOC entry 211 (class 1259 OID 741317)
-- Name: borrowers; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE borrowers (
    user_id integer NOT NULL,
    comment character varying(200)
);


--
-- TOC entry 212 (class 1259 OID 741320)
-- Name: borrowers_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW borrowers_view AS
 SELECT users.user_id,
    users.user_name,
    users.user_surname,
    borrowers.comment,
    users.user_phone,
    users.user_address,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = users.role_id)) AS role_name,
    users.password,
    users.user_email,
    users.activated,
    users.role_id
   FROM (borrowers
     JOIN users ON ((users.user_id = borrowers.user_id)));


--
-- TOC entry 213 (class 1259 OID 741325)
-- Name: branches; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE branches (
    branch_id integer NOT NULL,
    branch_name character varying(60) NOT NULL,
    branch_address character varying(60) NOT NULL,
    branch_phone character varying(15) NOT NULL,
    commnet character varying(100)
);


--
-- TOC entry 214 (class 1259 OID 741328)
-- Name: branches_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW branches_view AS
 SELECT branches.branch_id,
    branches.branch_name,
    branches.branch_address,
    branches.branch_phone,
    branches.commnet
   FROM branches;


--
-- TOC entry 215 (class 1259 OID 741332)
-- Name: cashbox; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE cashbox (
    cashbox_id integer NOT NULL,
    subaccount_id integer NOT NULL,
    information character varying(60),
    cashbox_address character varying(60)
);


--
-- TOC entry 216 (class 1259 OID 741335)
-- Name: cashbox_employee; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE cashbox_employee (
    cashbox_employee_id integer NOT NULL,
    cashbox_id integer NOT NULL,
    employee_id integer NOT NULL
);


--
-- TOC entry 217 (class 1259 OID 741338)
-- Name: cashbox_employee_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW cashbox_employee_view AS
 SELECT cashbox_employee.cashbox_employee_id,
    ( SELECT subaccounts.subaccount_number
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = c.subaccount_id)) AS subaccount_number,
    c.cashbox_address,
    u.user_name,
    u.user_surname,
    u.user_phone,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = u.role_id)) AS role_name,
    cashbox_employee.cashbox_id,
    cashbox_employee.employee_id
   FROM ((cashbox_employee
     JOIN cashbox c ON ((c.cashbox_id = cashbox_employee.cashbox_id)))
     JOIN users u ON ((u.user_id = cashbox_employee.employee_id)));


--
-- TOC entry 218 (class 1259 OID 741343)
-- Name: cashbox_transaction; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE cashbox_transaction (
    cashbox_transaction_id integer NOT NULL,
    cashbox_id integer,
    cashier_id integer,
    accountant_id integer,
    owner_id integer,
    payment_id integer,
    withdrawal_id integer
);


--
-- TOC entry 219 (class 1259 OID 741346)
-- Name: cashbox_transaction_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW cashbox_transaction_view AS
 SELECT cashbox_transaction.cashbox_transaction_id,
    cashbox_transaction.cashbox_id,
    cashbox_transaction.cashier_id,
    cashbox_transaction.accountant_id,
    cashbox_transaction.owner_id,
    cashbox_transaction.payment_id,
    cashbox_transaction.withdrawal_id
   FROM cashbox_transaction;


--
-- TOC entry 220 (class 1259 OID 741350)
-- Name: cashbox_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW cashbox_view AS
 SELECT cashbox.cashbox_id,
    s.subaccount_number,
    cashbox.information,
    cashbox.cashbox_address,
    cashbox.subaccount_id
   FROM (cashbox
     JOIN subaccounts s ON ((s.subaccount_id = cashbox.subaccount_id)));


--
-- TOC entry 221 (class 1259 OID 741354)
-- Name: chart_of_accounts; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE chart_of_accounts (
    chart_of_account_id integer NOT NULL,
    number_of_account character varying(5) NOT NULL,
    name_of_account character varying(150) NOT NULL,
    account_type_id integer
);


--
-- TOC entry 222 (class 1259 OID 741357)
-- Name: chart_of_accounts_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW chart_of_accounts_view AS
 SELECT chart_of_accounts.chart_of_account_id,
    chart_of_accounts.number_of_account,
    chart_of_accounts.name_of_account,
    at.account_type_name,
    chart_of_accounts.account_type_id
   FROM (chart_of_accounts
     JOIN account_type at ON ((at.account_type_id = chart_of_accounts.account_type_id)));


--
-- TOC entry 223 (class 1259 OID 741361)
-- Name: clients; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE clients (
    user_id integer NOT NULL,
    firm character varying(50) NOT NULL,
    firm_number character varying(10),
    location_id integer NOT NULL
);


--
-- TOC entry 224 (class 1259 OID 741364)
-- Name: locations; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE locations (
    location_id integer NOT NULL,
    country_name character varying(30) NOT NULL,
    country_code character varying(4) NOT NULL,
    region_name character varying(30) NOT NULL,
    city_name character varying(30) NOT NULL
);


--
-- TOC entry 225 (class 1259 OID 741367)
-- Name: clients_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 226 (class 1259 OID 741372)
-- Name: companies; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE companies (
    company_id integer NOT NULL,
    company_name character varying(60) NOT NULL,
    company_address character varying(60) NOT NULL,
    company_phone character varying(15) NOT NULL,
    comment character varying(100)
);


--
-- TOC entry 227 (class 1259 OID 741375)
-- Name: companies_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW companies_view AS
 SELECT companies.company_id,
    companies.company_name,
    companies.company_address,
    companies.company_phone,
    companies.comment
   FROM companies;


--
-- TOC entry 228 (class 1259 OID 741379)
-- Name: company_account; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE company_account (
    company_account_id integer NOT NULL,
    company_id integer NOT NULL,
    account_id integer NOT NULL
);


--
-- TOC entry 229 (class 1259 OID 741382)
-- Name: company_account_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 230 (class 1259 OID 741386)
-- Name: company_employee; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE company_employee (
    company_employee_id integer NOT NULL,
    company_id integer NOT NULL,
    employee_id integer NOT NULL,
    branch_id integer
);


--
-- TOC entry 231 (class 1259 OID 741389)
-- Name: company_employee_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW company_employee_view AS
 SELECT company_employee.company_employee_id,
    c.company_name,
    b.branch_name,
    e.user_name,
    e.user_surname,
    e.user_phone,
    company_employee.company_id,
    company_employee.employee_id,
    company_employee.branch_id
   FROM (((company_employee
     JOIN companies c ON ((c.company_id = company_employee.company_id)))
     JOIN users e ON ((e.user_id = company_employee.employee_id)))
     JOIN branches b ON ((b.branch_id = company_employee.branch_id)));


--
-- TOC entry 232 (class 1259 OID 741394)
-- Name: consume_product_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 233 (class 1259 OID 741397)
-- Name: measures; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE measures (
    measure_id integer NOT NULL,
    measure_name character varying(15) NOT NULL,
    measure_short_name character varying(4) NOT NULL,
    measure_unit integer
);


--
-- TOC entry 234 (class 1259 OID 741400)
-- Name: products; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 235 (class 1259 OID 741403)
-- Name: status; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE status (
    status_id integer NOT NULL,
    status_code character varying(4),
    status_name character varying(15),
    comment character varying(100)
);


--
-- TOC entry 3362 (class 0 OID 0)
-- Dependencies: 235
-- Name: COLUMN status.status_id; Type: COMMENT; Schema: OrmasSchema; Owner: -
--

COMMENT ON COLUMN status.status_id IS '
';


--
-- TOC entry 236 (class 1259 OID 741406)
-- Name: consume_product_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 237 (class 1259 OID 741411)
-- Name: consume_products; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 238 (class 1259 OID 741414)
-- Name: employees; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE employees (
    user_id integer NOT NULL,
    position_id integer NOT NULL,
    birth_date date NOT NULL,
    hire_date date NOT NULL
);


--
-- TOC entry 239 (class 1259 OID 741417)
-- Name: positions; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE positions (
    position_id integer NOT NULL,
    position_name character varying(50) NOT NULL
);


--
-- TOC entry 240 (class 1259 OID 741420)
-- Name: consume_products_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
     LEFT JOIN users u1 ON ((u1.user_id = consume_products.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = consume_products.employee_id)))
     LEFT JOIN status s ON ((s.status_id = consume_products.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = consume_products.currency_id)));


--
-- TOC entry 241 (class 1259 OID 741425)
-- Name: consume_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 242 (class 1259 OID 741428)
-- Name: consume_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 243 (class 1259 OID 741433)
-- Name: consume_raws; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 244 (class 1259 OID 741436)
-- Name: consume_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
     LEFT JOIN users u1 ON ((u1.user_id = consume_raws.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = consume_raws.employee_id)))
     LEFT JOIN status s ON ((s.status_id = consume_raws.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = consume_raws.currency_id)));


--
-- TOC entry 245 (class 1259 OID 741441)
-- Name: creditors; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE creditors (
    creditor_id integer NOT NULL,
    creditor_name character varying(100),
    creditor_address character varying(100),
    crediitor_phone character varying(20),
    company_id integer,
    user_id integer
);


--
-- TOC entry 246 (class 1259 OID 741444)
-- Name: creditors_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW creditors_view AS
 SELECT creditors.creditor_id,
    creditors.creditor_name,
    creditors.creditor_address,
    creditors.crediitor_phone,
    creditors.company_id,
    creditors.user_id
   FROM creditors;


--
-- TOC entry 247 (class 1259 OID 741448)
-- Name: currencies_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW currencies_view AS
 SELECT currencies.currency_id,
    currencies.currency_code,
    currencies.currency_short_name,
    currencies.currency_name,
    currencies.currency_unit,
    currencies.currency_main_trade
   FROM currencies;


--
-- TOC entry 248 (class 1259 OID 741452)
-- Name: division_account; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE division_account (
    division_account_id integer NOT NULL,
    division_id integer NOT NULL,
    account_id integer NOT NULL,
    account_code character varying(30) NOT NULL
);


--
-- TOC entry 249 (class 1259 OID 741455)
-- Name: divisions; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE divisions (
    division_id integer NOT NULL,
    division_name character varying(100) NOT NULL,
    division_code character varying(30) NOT NULL
);


--
-- TOC entry 250 (class 1259 OID 741458)
-- Name: division_account_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW division_account_view AS
 SELECT division_account.division_account_id,
    d.division_name,
    a.account_number,
    ( SELECT chart_of_accounts.name_of_account
           FROM chart_of_accounts
          WHERE ((chart_of_accounts.number_of_account)::text = (a.account_number)::text)) AS account_name,
    division_account.account_code,
    division_account.division_id,
    division_account.account_id
   FROM ((division_account
     JOIN divisions d ON ((d.division_id = division_account.division_id)))
     JOIN accounts a ON ((a.account_id = division_account.account_id)));


--
-- TOC entry 251 (class 1259 OID 741463)
-- Name: division_employee; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE division_employee (
    division_employee_id integer NOT NULL,
    division_id integer NOT NULL,
    employee_id integer,
    is_contract boolean DEFAULT false NOT NULL
);


--
-- TOC entry 252 (class 1259 OID 741467)
-- Name: division_employee_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW division_employee_view AS
 SELECT division_employee.division_employee_id,
    division_employee.division_id,
    division_employee.employee_id,
    division_employee.is_contract
   FROM division_employee;


--
-- TOC entry 253 (class 1259 OID 741471)
-- Name: divisions_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW divisions_view AS
 SELECT divisions.division_id,
    divisions.division_name,
    divisions.division_code
   FROM divisions;


--
-- TOC entry 254 (class 1259 OID 741475)
-- Name: employee_product; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE employee_product (
    employee_product_id integer NOT NULL,
    employee_id integer NOT NULL,
    product_id integer NOT NULL
);


--
-- TOC entry 255 (class 1259 OID 741478)
-- Name: employee_product_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW employee_product_view AS
 SELECT employee_product.employee_product_id,
    u.user_name,
    u.user_surname,
    u.user_phone,
    p.product_name,
    p.price,
    employee_product.employee_id,
    employee_product.product_id
   FROM ((employee_product
     JOIN users u ON ((u.user_id = employee_product.employee_id)))
     JOIN products p ON ((p.product_id = employee_product.product_id)));


--
-- TOC entry 256 (class 1259 OID 741483)
-- Name: employees_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
    employees.position_id,
    de.division_employee_id,
    de.division_id,
    de.is_contract
   FROM ((employees
     JOIN users ON ((users.user_id = employees.user_id)))
     JOIN division_employee de ON ((de.employee_id = employees.user_id)));


--
-- TOC entry 257 (class 1259 OID 741488)
-- Name: entries; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE entries (
    entry_id integer NOT NULL,
    entry_date timestamp without time zone NOT NULL,
    debiting_account_id integer NOT NULL,
    value numeric(20,3) NOT NULL,
    crediting_account_id integer NOT NULL,
    description character varying(200)
);


--
-- TOC entry 258 (class 1259 OID 741491)
-- Name: entry_operation; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE entry_operation (
    entry_operation_id integer NOT NULL,
    entry_id integer NOT NULL,
    operation_id integer NOT NULL
);


--
-- TOC entry 259 (class 1259 OID 741494)
-- Name: entry_subaccount; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE entry_subaccount (
    entry_subaccount_id integer NOT NULL,
    entry_id integer NOT NULL,
    subaccount_id integer NOT NULL
);


--
-- TOC entry 260 (class 1259 OID 741497)
-- Name: entries_full_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW entries_full_view AS
 SELECT entries.entry_id,
    to_char(entries.entry_date, 'dd.MM.yyyy'::text) AS entry_date,
    da.account_number AS debiting_account_number,
    entries.value,
    ca.account_number AS crediting_account_number,
    eo.operation_id,
    es.subaccount_id,
    entries.debiting_account_id,
    entries.crediting_account_id,
    entries.description
   FROM ((((entries
     LEFT JOIN accounts da ON ((da.account_id = entries.debiting_account_id)))
     LEFT JOIN entry_operation eo ON ((eo.entry_id = entries.entry_id)))
     LEFT JOIN entry_subaccount es ON ((es.entry_id = entries.entry_id)))
     LEFT JOIN accounts ca ON ((ca.account_id = entries.crediting_account_id)))
  ORDER BY entries.entry_date;


--
-- TOC entry 261 (class 1259 OID 741502)
-- Name: entries_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW entries_view AS
 SELECT entries.entry_id,
    to_char(entries.entry_date, 'dd.MM.yyyy'::text) AS entry_date,
    da.account_number AS debiting_account_number,
    entries.value,
    ca.account_number AS crediting_account_number,
    entries.debiting_account_id,
    entries.crediting_account_id,
    entries.description
   FROM ((entries
     JOIN accounts da ON ((da.account_id = entries.debiting_account_id)))
     JOIN accounts ca ON ((ca.account_id = entries.crediting_account_id)));


--
-- TOC entry 262 (class 1259 OID 741506)
-- Name: entry_operation_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW entry_operation_view AS
 SELECT entry_operation.entry_operation_id,
    entry_operation.entry_id,
    entry_operation.operation_id
   FROM entry_operation;


--
-- TOC entry 263 (class 1259 OID 741510)
-- Name: entry_routing; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE entry_routing (
    entry_routing_id integer NOT NULL,
    operation_name character varying(200) NOT NULL,
    debit integer NOT NULL,
    credit integer NOT NULL
);


--
-- TOC entry 264 (class 1259 OID 741513)
-- Name: entry_routing_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW entry_routing_view AS
 SELECT entry_routing.entry_routing_id,
    entry_routing.operation_name,
    entry_routing.debit,
    entry_routing.credit
   FROM entry_routing;


--
-- TOC entry 265 (class 1259 OID 741517)
-- Name: entry_subaccount_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW entry_subaccount_view AS
 SELECT entry_subaccount.entry_subaccount_id,
    entry_subaccount.entry_id,
    entry_subaccount.subaccount_id
   FROM entry_subaccount;


--
-- TOC entry 266 (class 1259 OID 741521)
-- Name: financial_report; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 267 (class 1259 OID 741524)
-- Name: financial_report_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 396 (class 1259 OID 742276)
-- Name: fixed_assets; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE fixed_assets (
    fixed_assets_id integer NOT NULL,
    fixed_assets_specification_id integer NOT NULL,
    inventory_number character varying(50),
    primary_cost numeric(17,3) NOT NULL,
    stop_cost numeric(17,3),
    service_life integer,
    is_amortize boolean,
    buy_date date,
    start_of_operation_date date,
    end_of_operation_date date,
    status_id integer,
    fixed_assets_details_id integer
);


--
-- TOC entry 397 (class 1259 OID 742281)
-- Name: fixed_assets_details; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE fixed_assets_details (
    fixed_assets_details_id integer NOT NULL,
    amortize_group_id integer,
    amortize_type_id integer,
    department_id integer,
    fixed_assets_location character varying(200),
    primary_cost_account_id integer,
    amortize_account_id integer,
    barcode_number character varying(50)
);


--
-- TOC entry 408 (class 1259 OID 742346)
-- Name: fixed_assets_details_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW fixed_assets_details_view AS
 SELECT fixed_assets_details.fixed_assets_details_id,
    ag.group_number,
    at.amortize_type_name,
    at.amortize_type_code,
    d.division_name,
    ps.current_balance AS primary_cost_value,
    ams.current_balance AS amortize_value,
    fixed_assets_details.barcode_number,
    fixed_assets_details.fixed_assets_location,
    fixed_assets_details.primary_cost_account_id,
    fixed_assets_details.amortize_group_id,
    fixed_assets_details.amortize_type_id,
    fixed_assets_details.department_id,
    fixed_assets_details.amortize_account_id
   FROM (((((fixed_assets_details
     LEFT JOIN amortize_group ag ON ((ag.amortize_group_id = fixed_assets_details.amortize_group_id)))
     LEFT JOIN amortize_type at ON ((at.amortize_type_id = fixed_assets_details.amortize_type_id)))
     LEFT JOIN divisions d ON ((d.division_id = fixed_assets_details.department_id)))
     LEFT JOIN subaccounts ps ON ((ps.subaccount_id = fixed_assets_details.primary_cost_account_id)))
     LEFT JOIN subaccounts ams ON ((ams.subaccount_id = fixed_assets_details.amortize_account_id)));


--
-- TOC entry 399 (class 1259 OID 742291)
-- Name: fixed_assets_operations; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE fixed_assets_operations (
    fixed_assets_operation_id integer NOT NULL,
    operation_date date,
    operation_name character varying(200),
    operation_value numeric(17,3),
    increment boolean,
    decrement boolean,
    fixed_assets_id integer
);


--
-- TOC entry 3363 (class 0 OID 0)
-- Dependencies: 399
-- Name: COLUMN fixed_assets_operations.increment; Type: COMMENT; Schema: OrmasSchema; Owner: -
--

COMMENT ON COLUMN fixed_assets_operations.increment IS '
';


--
-- TOC entry 401 (class 1259 OID 742308)
-- Name: fixed_assets_operations_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW fixed_assets_operations_view AS
 SELECT fixed_assets_operations.fixed_assets_operation_id,
    fixed_assets_operations.operation_date,
    fixed_assets_operations.operation_name,
    fixed_assets_operations.operation_value,
    fixed_assets_operations.increment,
    fixed_assets_operations.decrement,
    fixed_assets_operations.fixed_assets_id
   FROM fixed_assets_operations;


--
-- TOC entry 395 (class 1259 OID 742268)
-- Name: fixed_assets_specification; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE fixed_assets_specification (
    fixed_assets_specification_id integer NOT NULL,
    fixed_assets_name character varying(200),
    factory_number character varying(30),
    developer character varying(100),
    documnet character varying(200),
    object_characters character varying(400),
    condition character varying(100),
    date_of_construction date
);


--
-- TOC entry 400 (class 1259 OID 742304)
-- Name: fixed_assets_specification_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW fixed_assets_specification_view AS
 SELECT fixed_assets_specification.fixed_assets_specification_id,
    fixed_assets_specification.fixed_assets_name,
    fixed_assets_specification.factory_number,
    fixed_assets_specification.developer,
    fixed_assets_specification.documnet,
    fixed_assets_specification.object_characters,
    fixed_assets_specification.condition,
    fixed_assets_specification.date_of_construction
   FROM fixed_assets_specification;


--
-- TOC entry 409 (class 1259 OID 742356)
-- Name: fixed_assets_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW fixed_assets_view AS
 SELECT fixed_assets.fixed_assets_id,
    fs.fixed_assets_name,
    fixed_assets.inventory_number,
    fixed_assets.primary_cost,
    fixed_assets.stop_cost,
    ( SELECT subaccounts.current_balance
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = fd.primary_cost_account_id)) AS primary_cost_value,
    ( SELECT subaccounts.current_balance
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = fd.amortize_account_id)) AS amortize_value,
    ( SELECT divisions.division_name
           FROM divisions
          WHERE (divisions.division_id = fd.department_id)) AS division_name,
    s.status_name,
    fixed_assets.service_life,
    fixed_assets.is_amortize,
    fixed_assets.buy_date,
    fixed_assets.start_of_operation_date,
    fixed_assets.end_of_operation_date,
    fixed_assets.fixed_assets_specification_id,
    fixed_assets.status_id,
    fixed_assets.fixed_assets_details_id
   FROM (((fixed_assets
     LEFT JOIN fixed_assets_specification fs ON ((fs.fixed_assets_specification_id = fixed_assets.fixed_assets_specification_id)))
     LEFT JOIN fixed_assets_details fd ON ((fd.fixed_assets_details_id = fixed_assets.fixed_assets_details_id)))
     LEFT JOIN status s ON ((s.status_id = fixed_assets.status_id)));


--
-- TOC entry 268 (class 1259 OID 741528)
-- Name: id_seq; Type: SEQUENCE; Schema: OrmasSchema; Owner: -
--

CREATE SEQUENCE id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 9999999999
    CACHE 1;


--
-- TOC entry 269 (class 1259 OID 741530)
-- Name: inventorization_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 270 (class 1259 OID 741533)
-- Name: inventorization_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 271 (class 1259 OID 741538)
-- Name: inventorizations; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 272 (class 1259 OID 741541)
-- Name: inventorizations_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
     LEFT JOIN users u1 ON ((u1.user_id = inventorizations.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = inventorizations.employee_id)))
     LEFT JOIN status s ON ((s.status_id = inventorizations.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = inventorizations.currency_id)));


--
-- TOC entry 403 (class 1259 OID 742316)
-- Name: inventory; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE inventory (
    inventory_id integer NOT NULL,
    inventory_name character varying(200),
    inventory_cost numeric(17,3),
    department_id integer,
    location character varying(200),
    status_id integer,
    start_of_operation_date date,
    end_of_operation_date date,
    inventory_number character varying(50),
    barcode_number character varying(50)
);


--
-- TOC entry 3364 (class 0 OID 0)
-- Dependencies: 403
-- Name: COLUMN inventory.department_id; Type: COMMENT; Schema: OrmasSchema; Owner: -
--

COMMENT ON COLUMN inventory.department_id IS '
';


--
-- TOC entry 404 (class 1259 OID 742324)
-- Name: inventory_history; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE inventory_history (
    inventory_history_id integer NOT NULL,
    inventory_id integer,
    comment character varying(300),
    change_date date
);


--
-- TOC entry 405 (class 1259 OID 742333)
-- Name: inventory_history_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW inventory_history_view AS
 SELECT inventory_history.inventory_history_id,
    inventory_history.inventory_id,
    inventory_history.comment,
    inventory_history.change_date
   FROM inventory_history;


--
-- TOC entry 410 (class 1259 OID 742361)
-- Name: inventory_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW inventory_view AS
 SELECT inventory.inventory_id,
    inventory.inventory_name,
    inventory.inventory_cost,
    inventory.inventory_number,
    inventory.barcode_number,
    divisions.division_name,
    s.status_name,
    inventory.location,
    inventory.start_of_operation_date,
    inventory.end_of_operation_date,
    inventory.status_id,
    inventory.department_id
   FROM ((inventory
     LEFT JOIN status s ON ((s.status_id = inventory.status_id)))
     LEFT JOIN divisions ON ((divisions.division_id = inventory.department_id)));


--
-- TOC entry 273 (class 1259 OID 741546)
-- Name: jobprice; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 274 (class 1259 OID 741549)
-- Name: jobprice_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 275 (class 1259 OID 741554)
-- Name: jobsheet; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE jobsheet (
    jobsheet_id integer NOT NULL,
    jobsheet_date date NOT NULL,
    count numeric(20,3) NOT NULL,
    product_id integer NOT NULL,
    employee_id integer NOT NULL
);


--
-- TOC entry 276 (class 1259 OID 741557)
-- Name: jobsheet_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 277 (class 1259 OID 741562)
-- Name: locations_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW locations_view AS
 SELECT locations.location_id,
    locations.country_name,
    locations.country_code,
    locations.region_name,
    locations.city_name
   FROM locations;


--
-- TOC entry 278 (class 1259 OID 741566)
-- Name: measures_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW measures_view AS
 SELECT measures.measure_id,
    measures.measure_name,
    measures.measure_short_name,
    measures.measure_unit
   FROM measures;


--
-- TOC entry 279 (class 1259 OID 741570)
-- Name: net_cost; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE net_cost (
    net_cost_id integer NOT NULL,
    net_cost_date timestamp without time zone NOT NULL,
    net_cost_value numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    product_id integer NOT NULL,
    is_outdated boolean
);


--
-- TOC entry 280 (class 1259 OID 741573)
-- Name: net_cost_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 281 (class 1259 OID 741578)
-- Name: order_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 282 (class 1259 OID 741581)
-- Name: order_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 283 (class 1259 OID 741586)
-- Name: order_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 284 (class 1259 OID 741589)
-- Name: order_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 285 (class 1259 OID 741594)
-- Name: order_raws; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 286 (class 1259 OID 741597)
-- Name: purveyors; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE purveyors (
    user_id integer NOT NULL,
    company_name character varying(100) NOT NULL,
    location_id integer NOT NULL
);


--
-- TOC entry 287 (class 1259 OID 741600)
-- Name: order_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
     LEFT JOIN users u1 ON ((u1.user_id = order_raws.purveyor_id)))
     LEFT JOIN users u2 ON ((u2.user_id = order_raws.employee_id)))
     LEFT JOIN status s ON ((s.status_id = order_raws.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = order_raws.currency_id)));


--
-- TOC entry 288 (class 1259 OID 741605)
-- Name: orders; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 289 (class 1259 OID 741608)
-- Name: orders_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
     LEFT JOIN users u1 ON ((u1.user_id = orders.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = orders.employee_id)))
     LEFT JOIN status s ON ((s.status_id = orders.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = orders.currency_id)));


--
-- TOC entry 290 (class 1259 OID 741613)
-- Name: payment_employee; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE payment_employee (
    payment_employee_id integer NOT NULL,
    payment_id integer NOT NULL,
    employee_id integer NOT NULL
);


--
-- TOC entry 291 (class 1259 OID 741616)
-- Name: payment_employee_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW payment_employee_view AS
 SELECT payment_employee.payment_employee_id,
    payment_employee.payment_id,
    payment_employee.employee_id
   FROM payment_employee;


--
-- TOC entry 292 (class 1259 OID 741620)
-- Name: payments; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE payments (
    payment_id integer NOT NULL,
    payment_date timestamp without time zone NOT NULL,
    payment_value numeric(20,3) NOT NULL,
    payment_target character varying(100),
    user_id integer,
    currency_id integer NOT NULL,
    status_id integer NOT NULL,
    account_id integer,
    subaccount_id integer,
    who character varying(100),
    cashbox_account_id integer
);


--
-- TOC entry 293 (class 1259 OID 741623)
-- Name: payments_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW payments_view AS
 SELECT payments.payment_id,
    to_char(payments.payment_date, 'dd.MM.yyyy hh24:mm'::text) AS payment_date,
    u.user_name,
    u.user_surname,
    u.user_phone,
    payments.payment_value,
    c.currency_short_name AS currency_name,
    payments.payment_target,
    a.account_number,
    sa.subaccount_number,
    payments.who,
    s.status_name,
    payments.user_id,
    payments.currency_id,
    payments.status_id,
    payments.account_id,
    payments.subaccount_id,
    payments.cashbox_account_id
   FROM (((((payments
     LEFT JOIN currencies c ON ((c.currency_id = payments.currency_id)))
     LEFT JOIN status s ON ((s.status_id = payments.status_id)))
     LEFT JOIN accounts a ON ((a.account_id = payments.account_id)))
     LEFT JOIN subaccounts sa ON ((sa.subaccount_id = payments.subaccount_id)))
     LEFT JOIN users u ON ((u.user_id = payments.user_id)));


--
-- TOC entry 294 (class 1259 OID 741628)
-- Name: payslip_order; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE payslip_order (
    payslip_order_id integer NOT NULL,
    payslip_id integer NOT NULL,
    order_id integer
);


--
-- TOC entry 295 (class 1259 OID 741631)
-- Name: payslip_order_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW payslip_order_view AS
 SELECT payslip_order.payslip_order_id,
    payslip_order.payslip_id,
    payslip_order.order_id
   FROM payslip_order;


--
-- TOC entry 296 (class 1259 OID 741635)
-- Name: payslips; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE payslips (
    payslip_id integer NOT NULL,
    payslip_date timestamp without time zone,
    payslip_value numeric(20,3) NOT NULL,
    salary_id integer NOT NULL,
    currency_id integer NOT NULL
);


--
-- TOC entry 297 (class 1259 OID 741638)
-- Name: payslips_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW payslips_view AS
 SELECT payslips.payslip_id,
    to_char(payslips.payslip_date, 'dd.MM.yyyy hh24:mm'::text) AS payslip_date,
    payslips.payslip_value,
    c.currency_short_name AS currency_name,
    payslips.salary_id,
    payslips.currency_id
   FROM (payslips
     JOIN currencies c ON ((c.currency_id = payslips.currency_id)));


--
-- TOC entry 298 (class 1259 OID 741642)
-- Name: percent_rate; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE percent_rate (
    percent_rate_id integer NOT NULL,
    value numeric(20,3),
    condition character varying(100),
    position_id integer NOT NULL
);


--
-- TOC entry 299 (class 1259 OID 741645)
-- Name: percent_rate_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW percent_rate_view AS
 SELECT percent_rate.percent_rate_id,
    percent_rate.value,
    percent_rate.condition,
    percent_rate.position_id
   FROM (percent_rate
     JOIN positions p ON ((p.position_id = percent_rate.position_id)));


--
-- TOC entry 300 (class 1259 OID 741649)
-- Name: photos; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE photos (
    photo_id integer NOT NULL,
    user_id integer,
    product_id integer,
    photo_source character varying(100)
);


--
-- TOC entry 301 (class 1259 OID 741652)
-- Name: photos_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW photos_view AS
 SELECT photos.photo_id,
    photos.user_id,
    photos.product_id,
    photos.photo_source
   FROM photos;


--
-- TOC entry 302 (class 1259 OID 741656)
-- Name: positions_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW positions_view AS
 SELECT positions.position_id,
    positions.position_name
   FROM positions;


--
-- TOC entry 303 (class 1259 OID 741660)
-- Name: prices; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE prices (
    price_id integer NOT NULL,
    price_date timestamp without time zone NOT NULL,
    price_value numeric(20,5) NOT NULL,
    currency_id integer NOT NULL,
    product_id integer NOT NULL,
    is_outdated boolean
);


--
-- TOC entry 304 (class 1259 OID 741663)
-- Name: prices_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 305 (class 1259 OID 741668)
-- Name: product_branch; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE product_branch (
    product_branch_id integer NOT NULL,
    product_id integer NOT NULL,
    branch_id integer NOT NULL
);


--
-- TOC entry 306 (class 1259 OID 741671)
-- Name: product_branch_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW product_branch_view AS
 SELECT product_branch.product_branch_id,
    b.branch_name,
    b.branch_address,
    p.product_name,
    p.price,
    product_branch.product_id,
    product_branch.branch_id
   FROM ((product_branch
     JOIN products p ON ((p.product_id = product_branch.product_id)))
     JOIN branches b ON ((b.branch_id = product_branch.branch_id)));


--
-- TOC entry 307 (class 1259 OID 741675)
-- Name: product_type; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE product_type (
    product_type_id integer NOT NULL,
    product_type_name character varying(50) NOT NULL,
    product_type_short_name character varying(10) NOT NULL,
    product_type_code character varying(15)
);


--
-- TOC entry 308 (class 1259 OID 741678)
-- Name: product_types_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW product_types_view AS
 SELECT product_type.product_type_id,
    product_type.product_type_name,
    product_type.product_type_short_name,
    product_type.product_type_code
   FROM product_type;


--
-- TOC entry 309 (class 1259 OID 741682)
-- Name: production; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE production (
    production_id integer NOT NULL,
    production_date date NOT NULL,
    expiry_date date,
    session_start time without time zone NOT NULL,
    session_end time without time zone
);


--
-- TOC entry 310 (class 1259 OID 741685)
-- Name: production_consume_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 311 (class 1259 OID 741688)
-- Name: production_consume_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 312 (class 1259 OID 741693)
-- Name: production_consume_raws; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 313 (class 1259 OID 741696)
-- Name: production_consume_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
     LEFT JOIN status s ON ((s.status_id = production_consume_raws.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = production_consume_raws.currency_id)));


--
-- TOC entry 314 (class 1259 OID 741701)
-- Name: production_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 315 (class 1259 OID 741704)
-- Name: production_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 316 (class 1259 OID 741709)
-- Name: production_plan; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 317 (class 1259 OID 741712)
-- Name: production_plan_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 318 (class 1259 OID 741715)
-- Name: production_plan_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 319 (class 1259 OID 741720)
-- Name: production_plan_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 320 (class 1259 OID 741725)
-- Name: production_stock; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE production_stock (
    production_stock_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL,
    warehouse_id integer
);


--
-- TOC entry 321 (class 1259 OID 741728)
-- Name: warehouse; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE warehouse (
    warehouse_id integer NOT NULL,
    warehouse_name character varying(60) NOT NULL,
    warehouse_address character varying(60) NOT NULL,
    warehouse_phone character varying(15),
    warehouse_type_id integer NOT NULL,
    subaccount_id integer NOT NULL
);


--
-- TOC entry 322 (class 1259 OID 741731)
-- Name: production_stock_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
    w.warehouse_name,
    ( SELECT subaccounts.subaccount_number
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = w.subaccount_id)) AS subaccount_number,
    s.status_name,
    production_stock.product_id,
    production_stock.status_id,
    production_stock.currency_id,
    production_stock.warehouse_id
   FROM (((production_stock
     JOIN products p ON ((p.product_id = production_stock.product_id)))
     JOIN status s ON ((s.status_id = production_stock.status_id)))
     JOIN warehouse w ON ((w.warehouse_id = production_stock.warehouse_id)));


--
-- TOC entry 323 (class 1259 OID 741736)
-- Name: production_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW production_view AS
 SELECT production.production_id,
    to_char((production.production_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS production_date,
    to_char((production.expiry_date)::timestamp with time zone, 'dd.MM.yyyy'::text) AS expiry_date,
    to_char(('2001-09-28'::date + (production.session_start)::time with time zone), 'hh24:mm'::text) AS session_start,
    to_char(('2001-09-28'::date + (production.session_end)::time with time zone), 'hh24:mm'::text) AS session_end
   FROM production;


--
-- TOC entry 324 (class 1259 OID 741740)
-- Name: products_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
     JOIN currencies cur ON ((cur.currency_id = products.currency_id)))
  ORDER BY products.product_name;


--
-- TOC entry 325 (class 1259 OID 741745)
-- Name: purveyors_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 326 (class 1259 OID 741750)
-- Name: receipt_product_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 327 (class 1259 OID 741753)
-- Name: receipt_product_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 328 (class 1259 OID 741758)
-- Name: receipt_products; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 329 (class 1259 OID 741761)
-- Name: receipt_products_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
     LEFT JOIN users u1 ON ((u1.user_id = receipt_products.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = receipt_products.employee_id)))
     LEFT JOIN status s ON ((s.status_id = receipt_products.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = receipt_products.currency_id)));


--
-- TOC entry 330 (class 1259 OID 741766)
-- Name: refunds; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE refunds (
    refund_id integer NOT NULL,
    refund_date timestamp without time zone NOT NULL,
    refund_value numeric(20,3) NOT NULL,
    user_id integer NOT NULL,
    currency_id integer NOT NULL
);


--
-- TOC entry 331 (class 1259 OID 741769)
-- Name: refunds_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 332 (class 1259 OID 741773)
-- Name: relation_type; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE relation_type (
    relation_type_id integer NOT NULL,
    relation_name character varying(30) NOT NULL,
    comment character varying(100)
);


--
-- TOC entry 333 (class 1259 OID 741776)
-- Name: relation_type_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW relation_type_view AS
 SELECT relation_type.relation_type_id,
    relation_type.relation_name,
    relation_type.comment
   FROM relation_type;


--
-- TOC entry 334 (class 1259 OID 741780)
-- Name: relations; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE relations (
    relation_id integer NOT NULL,
    user_id_1 integer NOT NULL,
    user_id_2 integer NOT NULL,
    relation_type_id integer NOT NULL
);


--
-- TOC entry 335 (class 1259 OID 741783)
-- Name: relations_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 336 (class 1259 OID 741788)
-- Name: return_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 337 (class 1259 OID 741791)
-- Name: return_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 338 (class 1259 OID 741796)
-- Name: returns; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 339 (class 1259 OID 741799)
-- Name: returns_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
     LEFT JOIN users u1 ON ((u1.user_id = returns.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = returns.employee_id)))
     LEFT JOIN status s ON ((s.status_id = returns.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = returns.currency_id)));


--
-- TOC entry 340 (class 1259 OID 741804)
-- Name: roles_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW roles_view AS
 SELECT roles.role_id,
    roles.role_code,
    roles.role_name,
    roles.comment
   FROM roles;


--
-- TOC entry 341 (class 1259 OID 741808)
-- Name: salaries; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 342 (class 1259 OID 741811)
-- Name: salary_type; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE salary_type (
    salary_type_id integer NOT NULL,
    salary_type_code character varying(15) NOT NULL,
    salary_type_name character varying(30) NOT NULL
);


--
-- TOC entry 343 (class 1259 OID 741814)
-- Name: salaries_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 344 (class 1259 OID 741819)
-- Name: salary_type_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW salary_type_view AS
 SELECT salary_type.salary_type_id,
    salary_type.salary_type_code,
    salary_type.salary_type_name
   FROM salary_type;


--
-- TOC entry 345 (class 1259 OID 741823)
-- Name: shareholders; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE shareholders (
    user_id integer NOT NULL,
    count_of_stock numeric(20,3),
    informaton character varying(100)
);


--
-- TOC entry 346 (class 1259 OID 741826)
-- Name: shareholders_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW shareholders_view AS
 SELECT shareholders.user_id,
    users.user_name,
    users.user_surname,
    users.user_phone,
    users.user_address,
    shareholders.count_of_stock,
    shareholders.informaton
   FROM (shareholders
     JOIN users ON ((users.user_id = shareholders.user_id)));


--
-- TOC entry 347 (class 1259 OID 741830)
-- Name: specification_list; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE specification_list (
    specification_list_id integer NOT NULL,
    specification_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(20,5) NOT NULL
);


--
-- TOC entry 348 (class 1259 OID 741833)
-- Name: specification_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 349 (class 1259 OID 741837)
-- Name: specifications; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE specifications (
    specification_id integer NOT NULL,
    product_id integer NOT NULL,
    sum numeric(20,3) NOT NULL,
    currency_id integer NOT NULL,
    employee_id integer NOT NULL,
    specification_date timestamp without time zone NOT NULL
);


--
-- TOC entry 350 (class 1259 OID 741840)
-- Name: specifications_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
     LEFT JOIN products p ON ((p.product_id = specifications.product_id)))
     LEFT JOIN users u ON ((u.user_id = specifications.employee_id)))
     LEFT JOIN currencies c ON ((c.currency_id = specifications.currency_id)));


--
-- TOC entry 351 (class 1259 OID 741845)
-- Name: spoilage; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 352 (class 1259 OID 741848)
-- Name: spoilage_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 353 (class 1259 OID 741851)
-- Name: spoilage_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 354 (class 1259 OID 741856)
-- Name: spoilage_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
     LEFT JOIN employees_view e ON ((e.user_id = spoilage.employee_id)))
     LEFT JOIN currencies c ON ((c.currency_id = spoilage.currency_id)))
     LEFT JOIN status s ON ((s.status_id = spoilage.status_id)));


--
-- TOC entry 355 (class 1259 OID 741861)
-- Name: state; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE state (
    state_id integer NOT NULL,
    universal_id integer NOT NULL,
    status_id integer NOT NULL,
    last_change timestamp with time zone
);


--
-- TOC entry 356 (class 1259 OID 741864)
-- Name: state_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW state_view AS
 SELECT state.state_id,
    state.universal_id,
    state.status_id,
    to_char(state.last_change, 'dd.MM.yyyy hh24:mm'::text) AS last_change
   FROM state;


--
-- TOC entry 357 (class 1259 OID 741868)
-- Name: status_rule; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE status_rule (
    status_rule_id integer NOT NULL,
    operation character varying(50) NOT NULL,
    status_id integer NOT NULL
);


--
-- TOC entry 358 (class 1259 OID 741871)
-- Name: status_rule_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW status_rule_view AS
 SELECT status_rule.status_rule_id,
    status_rule.operation,
    s.status_name,
    status_rule.status_id
   FROM (status_rule
     JOIN status s ON ((s.status_id = status_rule.status_id)));


--
-- TOC entry 359 (class 1259 OID 741875)
-- Name: status_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW status_view AS
 SELECT status.status_id,
    status.status_code,
    status.status_name,
    status.comment
   FROM status;


--
-- TOC entry 360 (class 1259 OID 741879)
-- Name: stock; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE stock (
    stock_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL,
    warehouse_id integer
);


--
-- TOC entry 361 (class 1259 OID 741882)
-- Name: stock_history; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE stock_history (
    stock_id integer NOT NULL,
    product_id integer,
    count numeric(15,5),
    sum numeric(20,3),
    status_id integer,
    currency_id integer,
    warehouse_id integer,
    history_date timestamp without time zone
);


--
-- TOC entry 362 (class 1259 OID 741885)
-- Name: stock_history_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW stock_history_view AS
 SELECT stock_history.stock_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    stock_history.count,
    stock_history.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = stock_history.currency_id)) AS sum_currency_name,
    w.warehouse_name,
    ( SELECT subaccounts.subaccount_number
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = w.subaccount_id)) AS subaccount_number,
    s.status_name,
    stock_history.product_id,
    stock_history.status_id,
    stock_history.currency_id,
    stock_history.warehouse_id,
    stock_history.history_date
   FROM (((stock_history
     LEFT JOIN products p ON ((p.product_id = stock_history.product_id)))
     LEFT JOIN status s ON ((s.status_id = stock_history.status_id)))
     LEFT JOIN warehouse w ON ((w.warehouse_id = stock_history.warehouse_id)));


--
-- TOC entry 363 (class 1259 OID 741890)
-- Name: stock_transfer_list; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE stock_transfer_list (
    stock_transfer_list_id integer NOT NULL,
    stock_transfer_id integer NOT NULL,
    product_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


--
-- TOC entry 364 (class 1259 OID 741893)
-- Name: stock_transfer_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW stock_transfer_list_view AS
 SELECT stock_transfer_list.stock_transfer_list_id,
    stock_transfer_list.stock_transfer_id,
    p.product_name,
    p.price,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = p.currency_id)) AS currency_name,
    p.volume,
    ( SELECT measures.measure_name
           FROM measures
          WHERE (measures.measure_id = p.measure_id)) AS measure_name,
    stock_transfer_list.count,
    stock_transfer_list.sum,
    ( SELECT currencies.currency_short_name
           FROM currencies
          WHERE (currencies.currency_id = stock_transfer_list.currency_id)) AS sum_currency_name,
    s.status_name,
    stock_transfer_list.product_id,
    stock_transfer_list.status_id,
    stock_transfer_list.currency_id
   FROM ((stock_transfer_list
     JOIN products p ON ((p.product_id = stock_transfer_list.product_id)))
     JOIN status s ON ((s.status_id = stock_transfer_list.status_id)));


--
-- TOC entry 365 (class 1259 OID 741898)
-- Name: stock_transfers; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE stock_transfers (
    stock_transfer_id integer NOT NULL,
    user_id integer NOT NULL,
    stock_transfer_date timestamp without time zone NOT NULL,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3) NOT NULL,
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


--
-- TOC entry 366 (class 1259 OID 741901)
-- Name: stock_transfers_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW stock_transfers_view AS
 SELECT stock_transfers.stock_transfer_id,
    to_char(stock_transfers.stock_transfer_date, 'dd.MM.yyyy hh24:mm'::text) AS stock_transfer_date,
    to_char(stock_transfers.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
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
    stock_transfers.count,
    stock_transfers.sum,
    c.currency_short_name AS currency_name,
    stock_transfers.employee_id,
    stock_transfers.user_id,
    stock_transfers.status_id,
    stock_transfers.currency_id
   FROM ((((stock_transfers
     LEFT JOIN users u1 ON ((u1.user_id = stock_transfers.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = stock_transfers.employee_id)))
     LEFT JOIN status s ON ((s.status_id = stock_transfers.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = stock_transfers.currency_id)));


--
-- TOC entry 367 (class 1259 OID 741906)
-- Name: stock_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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
    w.warehouse_name,
    ( SELECT subaccounts.subaccount_number
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = w.subaccount_id)) AS subaccount_number,
    s.status_name,
    stock.product_id,
    stock.status_id,
    stock.currency_id,
    stock.warehouse_id
   FROM (((stock
     JOIN products p ON ((p.product_id = stock.product_id)))
     JOIN status s ON ((s.status_id = stock.status_id)))
     JOIN warehouse w ON ((w.warehouse_id = stock.warehouse_id)))
  ORDER BY p.product_name;


--
-- TOC entry 368 (class 1259 OID 741911)
-- Name: subaccount_history; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE subaccount_history (
    subaccount_history_id integer NOT NULL,
    subaccount_id integer NOT NULL,
    start_balance numeric(20,3) NOT NULL,
    current_balance numeric(20,3) NOT NULL,
    from_date date,
    till_date date
);


--
-- TOC entry 369 (class 1259 OID 741914)
-- Name: subaccount_history_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW subaccount_history_view AS
 SELECT subaccount_history.subaccount_history_id,
    subaccount_history.subaccount_id,
    subaccount_history.start_balance,
    subaccount_history.current_balance,
    subaccount_history.from_date,
    subaccount_history.till_date
   FROM subaccount_history;


--
-- TOC entry 370 (class 1259 OID 741918)
-- Name: subaccounts_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 371 (class 1259 OID 741923)
-- Name: taxes; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE taxes (
    tax_id integer NOT NULL,
    tax_name character(100) NOT NULL,
    tax_code character varying(15) NOT NULL,
    fixed_value numeric(20,3),
    percent_value integer,
    formula_value character varying(100)
);


--
-- TOC entry 372 (class 1259 OID 741926)
-- Name: taxes_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW taxes_view AS
 SELECT taxes.tax_id,
    taxes.tax_name,
    taxes.tax_code,
    taxes.fixed_value,
    taxes.percent_value,
    taxes.formula_value
   FROM taxes;


--
-- TOC entry 373 (class 1259 OID 741930)
-- Name: timesheet; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE timesheet (
    timesheet_id integer NOT NULL,
    salary_id integer NOT NULL,
    worked_time numeric(4,2) NOT NULL,
    timesheet_date date NOT NULL
);


--
-- TOC entry 374 (class 1259 OID 741933)
-- Name: timesheet_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 375 (class 1259 OID 741937)
-- Name: transport_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 376 (class 1259 OID 741940)
-- Name: transport_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 377 (class 1259 OID 741945)
-- Name: transports; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE transports (
    transport_id integer NOT NULL,
    user_id integer,
    transport_date timestamp without time zone,
    execution_date timestamp(0) without time zone,
    employee_id integer NOT NULL,
    count numeric(15,5),
    sum numeric(20,3),
    status_id integer,
    currency_id integer
);


--
-- TOC entry 378 (class 1259 OID 741948)
-- Name: transports_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW transports_view AS
 SELECT transports.transport_id,
    to_char(transports.transport_date, 'dd.MM.yyyy hh24:mm'::text) AS transport_date,
    to_char(transports.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
    s.status_code,
    s.status_name,
    u1.user_name,
    u1.user_surname,
    u1.user_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u1.user_id)))) AS user_position_name,
    u2.user_name AS employee_name,
    u2.user_surname AS employee_surname,
    u2.user_phone AS employee_phone,
    ( SELECT positions.position_name
           FROM positions
          WHERE (positions.position_id = ( SELECT employees.position_id
                   FROM employees
                  WHERE (employees.user_id = u2.user_id)))) AS employee_position_name,
    transports.count,
    transports.sum,
    c.currency_short_name AS currency_name,
    transports.employee_id,
    transports.user_id,
    transports.status_id,
    transports.currency_id
   FROM ((((transports
     LEFT JOIN users u1 ON ((u1.user_id = transports.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = transports.employee_id)))
     LEFT JOIN status s ON ((s.status_id = transports.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = transports.currency_id)));


--
-- TOC entry 379 (class 1259 OID 741953)
-- Name: users_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 380 (class 1259 OID 741957)
-- Name: warehouse_employee; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE warehouse_employee (
    warehouse_employee_id integer NOT NULL,
    warehouse_id integer NOT NULL,
    employee_id integer NOT NULL
);


--
-- TOC entry 381 (class 1259 OID 741960)
-- Name: warehouse_employee_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW warehouse_employee_view AS
 SELECT warehouse_employee.warehouse_employee_id,
    u.user_name,
    u.user_surname,
    u.user_phone,
    ( SELECT roles.role_name
           FROM roles
          WHERE (roles.role_id = u.role_id)) AS role_name,
    w.warehouse_name,
    ( SELECT subaccounts.subaccount_number
           FROM subaccounts
          WHERE (subaccounts.subaccount_id = w.subaccount_id)) AS subaccount_number,
    warehouse_employee.warehouse_id,
    warehouse_employee.employee_id
   FROM ((warehouse_employee
     JOIN warehouse w ON ((w.warehouse_id = warehouse_employee.warehouse_id)))
     JOIN users u ON ((u.user_id = warehouse_employee.employee_id)));


--
-- TOC entry 382 (class 1259 OID 741965)
-- Name: warehouse_type; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE warehouse_type (
    warehouse_type_id integer NOT NULL,
    warehouse_type_code character varying(20) NOT NULL,
    warehouse_type_purpose character varying(60),
    warehouse_type_name character varying(60) NOT NULL
);


--
-- TOC entry 383 (class 1259 OID 741968)
-- Name: warehouse_type_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW warehouse_type_view AS
 SELECT warehouse_type.warehouse_type_id,
    warehouse_type.warehouse_type_code,
    warehouse_type.warehouse_type_purpose,
    warehouse_type.warehouse_type_name
   FROM warehouse_type;


--
-- TOC entry 384 (class 1259 OID 741972)
-- Name: warehouse_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW warehouse_view AS
 SELECT warehouse.warehouse_id,
    warehouse.warehouse_name,
    s.subaccount_number,
    wt.warehouse_type_name,
    warehouse.warehouse_address,
    warehouse.warehouse_phone,
    warehouse.warehouse_type_id,
    warehouse.subaccount_id
   FROM ((warehouse
     JOIN warehouse_type wt ON ((wt.warehouse_type_id = warehouse.warehouse_type_id)))
     JOIN subaccounts s ON ((s.subaccount_id = warehouse.subaccount_id)));


--
-- TOC entry 385 (class 1259 OID 741977)
-- Name: withdrawals; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE withdrawals (
    withdrawal_id integer NOT NULL,
    withdrawal_date timestamp without time zone NOT NULL,
    withdrawal_value numeric(20,3) NOT NULL,
    user_id integer,
    subaccount_id integer,
    withdrawal_target character varying(100),
    currency_id integer,
    status_id integer,
    account_id integer,
    who character varying(100),
    cashbox_account_id integer
);


--
-- TOC entry 386 (class 1259 OID 741980)
-- Name: withdrawals_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW withdrawals_view AS
 SELECT withdrawals.withdrawal_id,
    to_char(withdrawals.withdrawal_date, 'dd.MM.yyyy hh24:mm'::text) AS withdrawal_date,
    withdrawals.withdrawal_value,
    c.currency_short_name AS currency_name,
    u.user_name,
    u.user_surname,
    u.user_phone,
    st.status_name,
    a.account_number,
    s.subaccount_number,
    withdrawals.who,
    withdrawals.withdrawal_target,
    withdrawals.user_id,
    withdrawals.currency_id,
    withdrawals.subaccount_id,
    st.status_id,
    a.account_id,
    withdrawals.cashbox_account_id
   FROM (((((withdrawals
     LEFT JOIN users u ON ((u.user_id = withdrawals.user_id)))
     LEFT JOIN currencies c ON ((c.currency_id = withdrawals.currency_id)))
     LEFT JOIN status st ON ((st.status_id = withdrawals.status_id)))
     LEFT JOIN subaccounts s ON ((s.subaccount_id = withdrawals.subaccount_id)))
     LEFT JOIN accounts a ON ((a.account_id = withdrawals.account_id)));


--
-- TOC entry 387 (class 1259 OID 741985)
-- Name: write_off_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 388 (class 1259 OID 741988)
-- Name: write_off_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 389 (class 1259 OID 741993)
-- Name: write_off_raw_list; Type: TABLE; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 390 (class 1259 OID 741996)
-- Name: write_off_raw_list_view; Type: VIEW; Schema: OrmasSchema; Owner: -
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


--
-- TOC entry 391 (class 1259 OID 742001)
-- Name: write_off_raws; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE write_off_raws (
    write_off_raw_id integer NOT NULL,
    user_id integer,
    write_off_raw_date timestamp without time zone NOT NULL,
    execution_date timestamp without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


--
-- TOC entry 392 (class 1259 OID 742004)
-- Name: write_off_raws_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW write_off_raws_view AS
 SELECT write_off_raws.write_off_raw_id,
    to_char(write_off_raws.write_off_raw_date, 'dd.MM.yyyy hh24:mm'::text) AS write_off_raw_date,
    to_char(write_off_raws.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
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
     LEFT JOIN users u1 ON ((u1.user_id = write_off_raws.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = write_off_raws.employee_id)))
     LEFT JOIN status s ON ((s.status_id = write_off_raws.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = write_off_raws.currency_id)));


--
-- TOC entry 393 (class 1259 OID 742009)
-- Name: write_offs; Type: TABLE; Schema: OrmasSchema; Owner: -
--

CREATE TABLE write_offs (
    write_off_id integer NOT NULL,
    user_id integer,
    write_off_date timestamp without time zone NOT NULL,
    execution_date timestamp without time zone,
    employee_id integer,
    count numeric(15,5) NOT NULL,
    sum numeric(20,3),
    status_id integer NOT NULL,
    currency_id integer NOT NULL
);


--
-- TOC entry 394 (class 1259 OID 742012)
-- Name: write_offs_view; Type: VIEW; Schema: OrmasSchema; Owner: -
--

CREATE VIEW write_offs_view AS
 SELECT write_offs.write_off_id,
    to_char(write_offs.write_off_date, 'dd.MM.yyyy hh24:mm'::text) AS write_off_date,
    to_char(write_offs.execution_date, 'dd.MM.yyyy hh24:mm'::text) AS execution_date,
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
     LEFT JOIN users u1 ON ((u1.user_id = write_offs.user_id)))
     LEFT JOIN users u2 ON ((u2.user_id = write_offs.employee_id)))
     LEFT JOIN status s ON ((s.status_id = write_offs.status_id)))
     LEFT JOIN currencies c ON ((c.currency_id = write_offs.currency_id)));


--
-- TOC entry 2895 (class 2606 OID 742018)
-- Name: access_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY accesses
    ADD CONSTRAINT access_pkey PRIMARY KEY (access_id);


--
-- TOC entry 2899 (class 2606 OID 742020)
-- Name: account_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY account_history
    ADD CONSTRAINT account_history_pkey PRIMARY KEY (account_history_id);


--
-- TOC entry 2909 (class 2606 OID 742022)
-- Name: account_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY accounts
    ADD CONSTRAINT account_pkey PRIMARY KEY (account_id);


--
-- TOC entry 2901 (class 2606 OID 742024)
-- Name: account_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY account_type
    ADD CONSTRAINT account_type_pkey PRIMARY KEY (account_type_id);


--
-- TOC entry 2903 (class 2606 OID 742026)
-- Name: accountable_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY accountable
    ADD CONSTRAINT accountable_pkey PRIMARY KEY (employee_id);


--
-- TOC entry 2905 (class 2606 OID 742028)
-- Name: accountable_trancation_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY accountable_transaction
    ADD CONSTRAINT accountable_trancation_pkey PRIMARY KEY (accountable_transaction_id);


--
-- TOC entry 3116 (class 2606 OID 742341)
-- Name: amortize_group_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY amortize_group
    ADD CONSTRAINT amortize_group_pkey PRIMARY KEY (amortize_group_id);


--
-- TOC entry 3108 (class 2606 OID 742290)
-- Name: amortize_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY amortize_type
    ADD CONSTRAINT amortize_type_pkey PRIMARY KEY (amortize_type_id);


--
-- TOC entry 2911 (class 2606 OID 742030)
-- Name: balance_payment_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY balance_payment
    ADD CONSTRAINT balance_payment_pkey PRIMARY KEY (balance_payment_id);


--
-- TOC entry 2913 (class 2606 OID 742032)
-- Name: balance_payslip_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY balance_payslip
    ADD CONSTRAINT balance_payslip_pkey PRIMARY KEY (balance_payslip_id);


--
-- TOC entry 2919 (class 2606 OID 742034)
-- Name: balance_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY balances
    ADD CONSTRAINT balance_pkey PRIMARY KEY (balance_id);


--
-- TOC entry 2915 (class 2606 OID 742036)
-- Name: balance_refund_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY balance_refund
    ADD CONSTRAINT balance_refund_pkey PRIMARY KEY (balance_refund_id);


--
-- TOC entry 2917 (class 2606 OID 742038)
-- Name: balance_withdrawal_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY balance_withdrawal
    ADD CONSTRAINT balance_withdrawal_pkey PRIMARY KEY (balance_withdrawal_id);


--
-- TOC entry 2925 (class 2606 OID 742040)
-- Name: borrower_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY borrowers
    ADD CONSTRAINT borrower_pkey PRIMARY KEY (user_id);


--
-- TOC entry 2927 (class 2606 OID 742042)
-- Name: branch_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY branches
    ADD CONSTRAINT branch_pkey PRIMARY KEY (branch_id);


--
-- TOC entry 2931 (class 2606 OID 742044)
-- Name: cashbox_employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY cashbox_employee
    ADD CONSTRAINT cashbox_employee_pkey PRIMARY KEY (cashbox_employee_id);


--
-- TOC entry 2929 (class 2606 OID 742046)
-- Name: cashbox_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY cashbox
    ADD CONSTRAINT cashbox_pkey PRIMARY KEY (cashbox_id);


--
-- TOC entry 2933 (class 2606 OID 742048)
-- Name: cashbox_transaction_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY cashbox_transaction
    ADD CONSTRAINT cashbox_transaction_pkey PRIMARY KEY (cashbox_transaction_id);


--
-- TOC entry 2935 (class 2606 OID 742050)
-- Name: char_of_account_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY chart_of_accounts
    ADD CONSTRAINT char_of_account_pkey PRIMARY KEY (chart_of_account_id);


--
-- TOC entry 2937 (class 2606 OID 742052)
-- Name: client_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY clients
    ADD CONSTRAINT client_pkey PRIMARY KEY (user_id);


--
-- TOC entry 2943 (class 2606 OID 742054)
-- Name: company_account_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY company_account
    ADD CONSTRAINT company_account_pkey PRIMARY KEY (company_account_id);


--
-- TOC entry 2945 (class 2606 OID 742056)
-- Name: company_employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY company_employee
    ADD CONSTRAINT company_employee_pkey PRIMARY KEY (company_employee_id);


--
-- TOC entry 2941 (class 2606 OID 742058)
-- Name: company_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY companies
    ADD CONSTRAINT company_pkey PRIMARY KEY (company_id);


--
-- TOC entry 2947 (class 2606 OID 742060)
-- Name: consume_product_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY consume_product_list
    ADD CONSTRAINT consume_product_list_pkey PRIMARY KEY (consume_product_list_id);


--
-- TOC entry 2955 (class 2606 OID 742062)
-- Name: consume_product_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY consume_products
    ADD CONSTRAINT consume_product_pkey PRIMARY KEY (consume_product_id);


--
-- TOC entry 2961 (class 2606 OID 742064)
-- Name: consume_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY consume_raw_list
    ADD CONSTRAINT consume_raw_list_pkey PRIMARY KEY (consume_raw_list_id);


--
-- TOC entry 2963 (class 2606 OID 742066)
-- Name: consume_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY consume_raws
    ADD CONSTRAINT consume_raw_pkey PRIMARY KEY (consume_raw_id);


--
-- TOC entry 2965 (class 2606 OID 742068)
-- Name: creditor_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY creditors
    ADD CONSTRAINT creditor_pkey PRIMARY KEY (creditor_id);


--
-- TOC entry 2921 (class 2606 OID 742070)
-- Name: currency_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY currencies
    ADD CONSTRAINT currency_pkey PRIMARY KEY (currency_id);


--
-- TOC entry 2967 (class 2606 OID 742072)
-- Name: division_account_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY division_account
    ADD CONSTRAINT division_account_pkey PRIMARY KEY (division_account_id);


--
-- TOC entry 2971 (class 2606 OID 742074)
-- Name: division_employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY division_employee
    ADD CONSTRAINT division_employee_pkey PRIMARY KEY (division_employee_id);


--
-- TOC entry 2969 (class 2606 OID 742076)
-- Name: division_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY divisions
    ADD CONSTRAINT division_pkey PRIMARY KEY (division_id);


--
-- TOC entry 2957 (class 2606 OID 742078)
-- Name: employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY employees
    ADD CONSTRAINT employee_pkey PRIMARY KEY (user_id);


--
-- TOC entry 2973 (class 2606 OID 742080)
-- Name: employee_product_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY employee_product
    ADD CONSTRAINT employee_product_pkey PRIMARY KEY (employee_product_id);


--
-- TOC entry 2978 (class 2606 OID 742082)
-- Name: entry_operation_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY entry_operation
    ADD CONSTRAINT entry_operation_pkey PRIMARY KEY (entry_operation_id);


--
-- TOC entry 2976 (class 2606 OID 742084)
-- Name: entry_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY entries
    ADD CONSTRAINT entry_pkey PRIMARY KEY (entry_id);


--
-- TOC entry 2982 (class 2606 OID 742086)
-- Name: entry_routing_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY entry_routing
    ADD CONSTRAINT entry_routing_pkey PRIMARY KEY (entry_routing_id);


--
-- TOC entry 2980 (class 2606 OID 742088)
-- Name: entry_subaccount_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY entry_subaccount
    ADD CONSTRAINT entry_subaccount_pkey PRIMARY KEY (entry_subaccount_id);


--
-- TOC entry 2984 (class 2606 OID 742090)
-- Name: financial_report_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY financial_report
    ADD CONSTRAINT financial_report_pkey PRIMARY KEY (financial_report_id);


--
-- TOC entry 3106 (class 2606 OID 742285)
-- Name: fixed_assets_details_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY fixed_assets_details
    ADD CONSTRAINT fixed_assets_details_pkey PRIMARY KEY (fixed_assets_details_id);


--
-- TOC entry 3110 (class 2606 OID 742295)
-- Name: fixed_assets_operations_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY fixed_assets_operations
    ADD CONSTRAINT fixed_assets_operations_pkey PRIMARY KEY (fixed_assets_operation_id);


--
-- TOC entry 3104 (class 2606 OID 742280)
-- Name: fixed_assets_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY fixed_assets
    ADD CONSTRAINT fixed_assets_pkey PRIMARY KEY (fixed_assets_id);


--
-- TOC entry 3102 (class 2606 OID 742275)
-- Name: fixed_assets_specification_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY fixed_assets_specification
    ADD CONSTRAINT fixed_assets_specification_pkey PRIMARY KEY (fixed_assets_specification_id);


--
-- TOC entry 2986 (class 2606 OID 742092)
-- Name: inventorization_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY inventorization_list
    ADD CONSTRAINT inventorization_list_pkey PRIMARY KEY (inventorization_list_id);


--
-- TOC entry 2988 (class 2606 OID 742094)
-- Name: inventorization_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY inventorizations
    ADD CONSTRAINT inventorization_pkey PRIMARY KEY (inventorization_id);


--
-- TOC entry 3112 (class 2606 OID 742323)
-- Name: inventory_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY inventory
    ADD CONSTRAINT inventory_pkey PRIMARY KEY (inventory_id);


--
-- TOC entry 3114 (class 2606 OID 742328)
-- Name: inventroy_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY inventory_history
    ADD CONSTRAINT inventroy_history_pkey PRIMARY KEY (inventory_history_id);


--
-- TOC entry 2990 (class 2606 OID 742096)
-- Name: jobprice_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY jobprice
    ADD CONSTRAINT jobprice_pkey PRIMARY KEY (jobprice_id);


--
-- TOC entry 2992 (class 2606 OID 742098)
-- Name: jobsheet_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY jobsheet
    ADD CONSTRAINT jobsheet_pkey PRIMARY KEY (jobsheet_id);


--
-- TOC entry 2949 (class 2606 OID 742100)
-- Name: measure_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY measures
    ADD CONSTRAINT measure_pkey PRIMARY KEY (measure_id);


--
-- TOC entry 2893 (class 2606 OID 742102)
-- Name: menu_item_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY access_items
    ADD CONSTRAINT menu_item_pkey PRIMARY KEY (access_item_id);


--
-- TOC entry 2994 (class 2606 OID 742104)
-- Name: net_cost_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY net_cost
    ADD CONSTRAINT net_cost_pkey PRIMARY KEY (net_cost_id);


--
-- TOC entry 2996 (class 2606 OID 742106)
-- Name: order_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY order_list
    ADD CONSTRAINT order_list_pkey PRIMARY KEY (order_list_id);


--
-- TOC entry 3004 (class 2606 OID 742108)
-- Name: order_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY orders
    ADD CONSTRAINT order_pkey PRIMARY KEY (order_id);


--
-- TOC entry 2998 (class 2606 OID 742110)
-- Name: order_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY order_raw_list
    ADD CONSTRAINT order_raw_list_pkey PRIMARY KEY (order_raw_list_id);


--
-- TOC entry 3000 (class 2606 OID 742112)
-- Name: order_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY order_raws
    ADD CONSTRAINT order_raw_pkey PRIMARY KEY (order_raw_id);


--
-- TOC entry 3006 (class 2606 OID 742114)
-- Name: payment_employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY payment_employee
    ADD CONSTRAINT payment_employee_pkey PRIMARY KEY (payment_employee_id);


--
-- TOC entry 3008 (class 2606 OID 742116)
-- Name: payment_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY payments
    ADD CONSTRAINT payment_pkey PRIMARY KEY (payment_id);


--
-- TOC entry 3010 (class 2606 OID 742118)
-- Name: payslip_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY payslips
    ADD CONSTRAINT payslip_pkey PRIMARY KEY (payslip_id);


--
-- TOC entry 3012 (class 2606 OID 742120)
-- Name: percent_rate_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY percent_rate
    ADD CONSTRAINT percent_rate_pkey PRIMARY KEY (percent_rate_id);


--
-- TOC entry 3014 (class 2606 OID 742122)
-- Name: photo_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY photos
    ADD CONSTRAINT photo_pkey PRIMARY KEY (photo_id);


--
-- TOC entry 2959 (class 2606 OID 742124)
-- Name: position_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY positions
    ADD CONSTRAINT position_pkey PRIMARY KEY (position_id);


--
-- TOC entry 3016 (class 2606 OID 742126)
-- Name: price_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY prices
    ADD CONSTRAINT price_pkey PRIMARY KEY (price_id);


--
-- TOC entry 3018 (class 2606 OID 742128)
-- Name: product_branch_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY product_branch
    ADD CONSTRAINT product_branch_pkey PRIMARY KEY (product_branch_id);


--
-- TOC entry 2951 (class 2606 OID 742130)
-- Name: product_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY products
    ADD CONSTRAINT product_pkey PRIMARY KEY (product_id);


--
-- TOC entry 3020 (class 2606 OID 742132)
-- Name: product_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY product_type
    ADD CONSTRAINT product_type_pkey PRIMARY KEY (product_type_id);


--
-- TOC entry 3024 (class 2606 OID 742134)
-- Name: production_consume_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY production_consume_raw_list
    ADD CONSTRAINT production_consume_raw_list_pkey PRIMARY KEY (consume_raw_list_id);


--
-- TOC entry 3026 (class 2606 OID 742136)
-- Name: production_consume_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY production_consume_raws
    ADD CONSTRAINT production_consume_raw_pkey PRIMARY KEY (consume_raw_id);


--
-- TOC entry 3028 (class 2606 OID 742138)
-- Name: production_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY production_list
    ADD CONSTRAINT production_list_pkey PRIMARY KEY (production_list_id);


--
-- TOC entry 3022 (class 2606 OID 742140)
-- Name: production_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY production
    ADD CONSTRAINT production_pkey PRIMARY KEY (production_id);


--
-- TOC entry 3032 (class 2606 OID 742142)
-- Name: production_plan_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY production_plan_list
    ADD CONSTRAINT production_plan_list_pkey PRIMARY KEY (production_plan_list_id);


--
-- TOC entry 3030 (class 2606 OID 742144)
-- Name: production_plan_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY production_plan
    ADD CONSTRAINT production_plan_pkey PRIMARY KEY (production_plan_id);


--
-- TOC entry 3034 (class 2606 OID 742146)
-- Name: production_stock_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY production_stock
    ADD CONSTRAINT production_stock_pkey PRIMARY KEY (production_stock_id);


--
-- TOC entry 3002 (class 2606 OID 742148)
-- Name: purveyor_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY purveyors
    ADD CONSTRAINT purveyor_pkey PRIMARY KEY (user_id);


--
-- TOC entry 3038 (class 2606 OID 742150)
-- Name: receipt_product_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY receipt_product_list
    ADD CONSTRAINT receipt_product_list_pkey PRIMARY KEY (receipt_product_list_id);


--
-- TOC entry 3040 (class 2606 OID 742152)
-- Name: receipt_product_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY receipt_products
    ADD CONSTRAINT receipt_product_pkey PRIMARY KEY (receipt_product_id);


--
-- TOC entry 3042 (class 2606 OID 742154)
-- Name: refund_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY refunds
    ADD CONSTRAINT refund_pkey PRIMARY KEY (refund_id);


--
-- TOC entry 2939 (class 2606 OID 742156)
-- Name: region_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY locations
    ADD CONSTRAINT region_pkey PRIMARY KEY (location_id);


--
-- TOC entry 3044 (class 2606 OID 742158)
-- Name: relarion_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY relation_type
    ADD CONSTRAINT relarion_type_pkey PRIMARY KEY (relation_type_id);


--
-- TOC entry 3046 (class 2606 OID 742160)
-- Name: relation_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY relations
    ADD CONSTRAINT relation_pkey PRIMARY KEY (relation_id);


--
-- TOC entry 3048 (class 2606 OID 742162)
-- Name: return_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY return_list
    ADD CONSTRAINT return_list_pkey PRIMARY KEY (return_list_id);


--
-- TOC entry 3050 (class 2606 OID 742164)
-- Name: return_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY returns
    ADD CONSTRAINT return_pkey PRIMARY KEY (return_id);


--
-- TOC entry 2897 (class 2606 OID 742166)
-- Name: role_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY roles
    ADD CONSTRAINT role_pkey PRIMARY KEY (role_id);


--
-- TOC entry 3052 (class 2606 OID 742168)
-- Name: salary_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY salaries
    ADD CONSTRAINT salary_pkey PRIMARY KEY (salary_id);


--
-- TOC entry 3054 (class 2606 OID 742170)
-- Name: salary_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY salary_type
    ADD CONSTRAINT salary_type_pkey PRIMARY KEY (salary_type_id);


--
-- TOC entry 3056 (class 2606 OID 742172)
-- Name: shareholder_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY shareholders
    ADD CONSTRAINT shareholder_pkey PRIMARY KEY (user_id);


--
-- TOC entry 3058 (class 2606 OID 742174)
-- Name: specification_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY specification_list
    ADD CONSTRAINT specification_list_pkey PRIMARY KEY (specification_list_id);


--
-- TOC entry 3060 (class 2606 OID 742176)
-- Name: specification_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY specifications
    ADD CONSTRAINT specification_pkey PRIMARY KEY (specification_id);


--
-- TOC entry 3064 (class 2606 OID 742178)
-- Name: spoilage_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY spoilage_list
    ADD CONSTRAINT spoilage_list_pkey PRIMARY KEY (spoilage_list_id);


--
-- TOC entry 3062 (class 2606 OID 742180)
-- Name: spoilage_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY spoilage
    ADD CONSTRAINT spoilage_pkey PRIMARY KEY (spoilage_id);


--
-- TOC entry 3066 (class 2606 OID 742182)
-- Name: state_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY state
    ADD CONSTRAINT state_pkey PRIMARY KEY (state_id);


--
-- TOC entry 2953 (class 2606 OID 742184)
-- Name: status_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY status
    ADD CONSTRAINT status_pkey PRIMARY KEY (status_id);


--
-- TOC entry 3068 (class 2606 OID 742186)
-- Name: status_rule_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY status_rule
    ADD CONSTRAINT status_rule_pkey PRIMARY KEY (status_rule_id);


--
-- TOC entry 3072 (class 2606 OID 742188)
-- Name: stock_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY stock_history
    ADD CONSTRAINT stock_history_pkey PRIMARY KEY (stock_id);


--
-- TOC entry 3070 (class 2606 OID 742190)
-- Name: stock_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY stock
    ADD CONSTRAINT stock_pkey PRIMARY KEY (stock_id);


--
-- TOC entry 3074 (class 2606 OID 742192)
-- Name: stock_transfer_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY stock_transfer_list
    ADD CONSTRAINT stock_transfer_list_pkey PRIMARY KEY (stock_transfer_list_id);


--
-- TOC entry 3076 (class 2606 OID 742194)
-- Name: stock_transfers_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY stock_transfers
    ADD CONSTRAINT stock_transfers_pkey PRIMARY KEY (stock_transfer_id);


--
-- TOC entry 3078 (class 2606 OID 742196)
-- Name: subaccount_history_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY subaccount_history
    ADD CONSTRAINT subaccount_history_pkey PRIMARY KEY (subaccount_history_id);


--
-- TOC entry 2923 (class 2606 OID 742198)
-- Name: subaccount_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY subaccounts
    ADD CONSTRAINT subaccount_pkey PRIMARY KEY (subaccount_id);


--
-- TOC entry 3080 (class 2606 OID 742200)
-- Name: tax_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY taxes
    ADD CONSTRAINT tax_pkey PRIMARY KEY (tax_id);


--
-- TOC entry 3082 (class 2606 OID 742202)
-- Name: timesheet_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY timesheet
    ADD CONSTRAINT timesheet_pkey PRIMARY KEY (timesheet_id);


--
-- TOC entry 3084 (class 2606 OID 742204)
-- Name: transport_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY transport_list
    ADD CONSTRAINT transport_list_pkey PRIMARY KEY (transport_list_id);


--
-- TOC entry 3086 (class 2606 OID 742206)
-- Name: transport_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY transports
    ADD CONSTRAINT transport_pkey PRIMARY KEY (transport_id);


--
-- TOC entry 2907 (class 2606 OID 742208)
-- Name: user_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY users
    ADD CONSTRAINT user_pkey PRIMARY KEY (user_id);


--
-- TOC entry 3088 (class 2606 OID 742210)
-- Name: warehouse_employee_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY warehouse_employee
    ADD CONSTRAINT warehouse_employee_pkey PRIMARY KEY (warehouse_employee_id);


--
-- TOC entry 3036 (class 2606 OID 742212)
-- Name: warehouse_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY warehouse
    ADD CONSTRAINT warehouse_pkey PRIMARY KEY (warehouse_id);


--
-- TOC entry 3090 (class 2606 OID 742214)
-- Name: warehouse_type_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY warehouse_type
    ADD CONSTRAINT warehouse_type_pkey PRIMARY KEY (warehouse_type_id);


--
-- TOC entry 3098 (class 2606 OID 742216)
-- Name: wite_off_raw_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY write_off_raws
    ADD CONSTRAINT wite_off_raw_pkey PRIMARY KEY (write_off_raw_id);


--
-- TOC entry 3092 (class 2606 OID 742218)
-- Name: withdrawal_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY withdrawals
    ADD CONSTRAINT withdrawal_pkey PRIMARY KEY (withdrawal_id);


--
-- TOC entry 3094 (class 2606 OID 742220)
-- Name: write_off_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY write_off_list
    ADD CONSTRAINT write_off_list_pkey PRIMARY KEY (write_off_list_id);


--
-- TOC entry 3100 (class 2606 OID 742222)
-- Name: write_off_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY write_offs
    ADD CONSTRAINT write_off_pkey PRIMARY KEY (write_off_id);


--
-- TOC entry 3096 (class 2606 OID 742224)
-- Name: write_off_raw_list_pkey; Type: CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY write_off_raw_list
    ADD CONSTRAINT write_off_raw_list_pkey PRIMARY KEY (write_off_raw_list_id);


--
-- TOC entry 2974 (class 1259 OID 742225)
-- Name: entry_date_index; Type: INDEX; Schema: OrmasSchema; Owner: -
--

CREATE INDEX entry_date_index ON entries USING btree (entry_date DESC);


--
-- TOC entry 3117 (class 2606 OID 742226)
-- Name: access_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY accesses
    ADD CONSTRAINT access_fkey FOREIGN KEY (access_item_id) REFERENCES access_items(access_item_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3118 (class 2606 OID 742231)
-- Name: balance_subaccount_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY balances
    ADD CONSTRAINT balance_subaccount_fkey FOREIGN KEY (subaccount_id) REFERENCES subaccounts(subaccount_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3119 (class 2606 OID 742236)
-- Name: balance_user_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY balances
    ADD CONSTRAINT balance_user_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3120 (class 2606 OID 742241)
-- Name: client_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY clients
    ADD CONSTRAINT client_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3121 (class 2606 OID 742246)
-- Name: employee_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY employees
    ADD CONSTRAINT employee_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3122 (class 2606 OID 742251)
-- Name: purveyor_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY purveyors
    ADD CONSTRAINT purveyor_fkey FOREIGN KEY (user_id) REFERENCES users(user_id) ON UPDATE CASCADE ON DELETE CASCADE;


--
-- TOC entry 3123 (class 2606 OID 742256)
-- Name: salary_fkey; Type: FK CONSTRAINT; Schema: OrmasSchema; Owner: -
--

ALTER TABLE ONLY salaries
    ADD CONSTRAINT salary_fkey FOREIGN KEY (user_id) REFERENCES users(user_id);


--
-- TOC entry 3358 (class 0 OID 0)
-- Dependencies: 7
-- Name: OrmasSchema; Type: ACL; Schema: -; Owner: -
--

REVOKE ALL ON SCHEMA "OrmasSchema" FROM PUBLIC;
REVOKE ALL ON SCHEMA "OrmasSchema" FROM postgres;
GRANT ALL ON SCHEMA "OrmasSchema" TO postgres;
GRANT ALL ON SCHEMA "OrmasSchema" TO PUBLIC;


--
-- TOC entry 3360 (class 0 OID 0)
-- Dependencies: 8
-- Name: public; Type: ACL; Schema: -; Owner: -
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


-- Completed on 2019-11-24 20:01:05

--
-- PostgreSQL database dump complete
--

